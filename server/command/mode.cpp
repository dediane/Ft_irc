/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:32 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/18 13:48:03 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//User modes
// - [o] - User is an operator.
// - [w] - User receives wallops;
// - [r] - restricted user connection.


//Channel modes
// [O] - give "channel creator" status;
// [o] - give/take channel operator privilege;

// [t] - toggle the topic settable by channel operator only flag;
// [i] - toggle the invite-only channel flag;
// [n] - toggle the no messages to channel from clients on the outside;
// [m] - toggle the moderated channel;
// [v] - give/take the ability to speak on a moderated channel;

void removeDuplicates(std::string& str)
{
    std::string::iterator i = str.begin();
    std::string::iterator k = str.begin();
    while (i != str.end()) 
    {
        std::string::iterator j = str.begin();
        while (j != i) 
        {
            if (*j == *i) 
            {
                break;
            }
            j++;
        }
        if (j == i) 
        {
            *k = *i;
            k++;
        }
        i++;
    }
    str.erase(k, str.end());
}

//check if the mode is valid
bool isvalid_mode(std::string str, std::string charset, User *user)
{
    //mode valid for channel : [t][i][n][m][v]  && [o] for user in channel
    //mode valid for user: [o][i][w]
    (void)user;

    if (str.size() > 1)
    {
        std::string strs = charset;
        if (!(*str.begin() == '+' || *str.begin() == '-'))
            return(false); 
        std::string::iterator it;
        for (it = str.begin() + 1; it != str.end(); it++)
        {
            if (charset.find(*it) == std::string::npos)
            {
                send_reply(user->getFd(), user->getPrefix() + " 472 " + (*it) + " :is unknown mode char to me\r\n");
                return false;
            }
        }
        return true;
    }
    return false;
}

std::string addmode(std::string mode, std::string oldmode)
{
    std::string::iterator it;
    std::string::iterator it2;
    mode.erase(0,1);
    std::string copy = mode;
    for (it = mode.begin(); it != mode.end(); ++it)
    {
        for (it2 = oldmode.begin() + 1; it2 != oldmode.end(); ++it2)
        {
            if (*it == *it2)
            {
                size_t found = copy.find(*it);
                if (found != std::string::npos)
                    copy.erase(found, 1);
            }
        }
    }
    oldmode.append(copy);
    return (oldmode);
}

std::string deletemode(std::string mode, std::string oldmode)
{
    std::string::iterator it;
    std::string::iterator it2;
    std::string copy = oldmode;
    mode.erase(0,1);
    for (it = mode.begin(); it != mode.end(); ++it)
    {
        for (it2 = oldmode.begin() + 1; it2 != oldmode.end(); ++it2)
        {
            if (*it == *it2)
               copy.erase(copy.find(*it), 1);
        }
    }
    return (copy);
}

void mode_channel(Message *msg, std::vector<std::string> message)
{
    Server *server = msg->getserver();
    Channel *channel;
    User *user = msg->getuser();
    User *target;
    User *channel_user;
    std::string mode;


    if(!(channel = server->get_channel_by_name(message[1])))
        return (send_reply(user->getFd(), user->getPrefix() + " 403 " + ERR_NOSUCHCHANNEL(message[1])));
    if (message.size() == 4)
    {
        if(!channel->is_usermode(user->getFd(), 'o'))
            return (send_reply(user->getFd(), user->getPrefix() + " 482 " + user->getNickname() + " " + ERR_CHANOPRIVNEEDED(channel->getName())));
        mode = message[2];
        if (!(target = server->get_user_by_nickname(message[3])))
            return (send_reply(user->getFd(), user->getPrefix() + " 401 " + ERR_NOSUCHNICK(message[3])));
        if (!channel->isUserinChannel(*target))
            return (send_reply(user->getFd(), user->getPrefix() + " 442 " + ERR_NOTONCHANNEL(message[3])));
        channel_user = channel->get_user(target);
        removeDuplicates(mode);
        if (isvalid_mode(mode, "ov", user) == true)
        {
            std::string new_mode;
            if (!channel->getUserMode(channel_user->getFd()).empty() && *mode.begin() == '+')
                new_mode =  addmode(mode, channel->getUserMode(channel_user->getFd()));
            else if  (!channel->getUserMode(channel_user->getFd()).empty() && *mode.begin() == '-')
                new_mode = deletemode(mode, channel->getUserMode(channel_user->getFd()));
            channel->ChangeMode(target->getFd(), new_mode);
            std::string tmp = mode;
            mode = user->getNickname() + " " + channel->getName() + " " + tmp + " " + target->getNickname(); 
            send_reply(user->getFd(), RPL_CHANNELMODEIS(user, channel, mode));
            send_reply(target->getFd(), RPL_CHANNELMODEIS(user, channel, mode));
            return;
        }
    }
    if (message.size() == 3)
    {
        if ((message[2].size() == 1) && (message[2].find("b") != std::string::npos))
            return;
        if(!channel->is_usermode(user->getFd(), 'o'))
            return (send_reply(user->getFd(), user->getPrefix() + " 482 " + user->getNickname() + " " + ERR_CHANOPRIVNEEDED(channel->getName())));
        mode = message[2];
        removeDuplicates(mode);
        if (isvalid_mode(mode, "tinm", user) == true)
        {   
            if (!channel->getMode().empty() && *mode.begin() == '+')
                channel->setMode(addmode(mode, channel->getMode()));
            else if (!channel->getMode().empty() && *mode.begin() == '-')
                channel->setMode(deletemode(mode, channel->getMode()));
        }
    }
    if (message.size() <= 3)
        send_reply(user->getFd(), RPL_CHANNELMODEIS(user, channel, user->getNickname() + " " + channel->getName() + " " + channel->getMode()));
    return;
}

void mode_user(Message *msg, std::vector<std::string> message)
{
    Server *server = msg->getserver();
    User *user = msg->getuser();
    User *target;
    std::string mode;

    if(!(target = server->get_user_by_nickname(message[1])))
        return (send_reply(user->getFd(), user->getPrefix() + " 401 " + ERR_NOSUCHNICK(message[1])));
    if (target->getNickname() != user->getNickname())
        return (send_reply(user->getFd(), user->getPrefix() + " 502 " + ERR_USERSDONTMATCH()));
    if (message.size() == 3)
    {
        mode = message[2];
        removeDuplicates(mode);
        if (isvalid_mode(mode, "oiw", user) == true)
        {
            if (!user->getMode().empty() && *mode.begin() == '+')
            {
                user->setMode(addmode(mode, user->getMode()));
                if (mode.find('o'))
                    user->setMode(deletemode("o", user->getMode()));
            } 
            else if (!user->getMode().empty() && *mode.begin() == '-')
                user->setMode(deletemode(mode, user->getMode()));
        }
    }
    send_reply(user->getFd(), RPL_UMODEIS(user));
    return;
}

void Command::mode(Message *msg, std::vector<std::string> message)
{
    User    *usr = msg->getuser();
    Server  *server = msg->getserver();
    (void)server;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NEEDMOREPARAMS("MODE")));
    if (message[1].find("#") != std::string::npos)
        mode_channel(msg, message);
    else if (message.size() < 4)
        mode_user(msg, message);
    return;
}