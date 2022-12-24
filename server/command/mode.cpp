/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/24 12:08:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//User modes
// - [o] - User is an operator (prefix @).
// - [w] - User receives wallops;
// - [r] - restricted user connection.


//Channel modes
// [O] - give "channel creator" status;
// [o] - give/take channel operator privilege;
// [v] - give/take the voice privilege;

// [a] - toggle the anonymous channel flag;
// [i] - toggle the invite-only channel flag;
// [m] - toggle the moderated channel;
// [n] - toggle the no messages to channel from clients on the outside;
// [q] - toggle the quiet channel flag;
// [p] - toggle the private channel flag;
// [s] - toggle the secret channel flag;
// [r] - toggle the server reop channel flag;
// [t] - toggle the topic settable by channel operator only flag;

// [k] - set/remove the channel key (password);
// [l] - set/remove the user limit to channel;

// [b] - set/remove ban mask to keep users out;
// [e] - set/remove an exception mask to override a ban mask;
// [I] - set/remove an invitation mask to automatically override the invite-only flag;

bool isvalid_mode_channel(std::string mode)
{
    //mode valid : [t][i][k][n][m][v]
    if (mode.size() > 1)
    {
        std::string modes = "tiknmv";
        std::string::iterator it;
        std::string::iterator it2;
        if (!(*mode.begin() == '+' || *mode.begin() == '-'))
            return(false); 
        for (it2 = mode.begin() + 1 ; it2 != mode.end(); it2++)
        {
            it = modes.begin();
            for (it = modes.begin(); it != modes.end(); it++)
                if (!mode.find(*it))
                    return(false); //"ERROR 472"
        }
        return (true);
    }
    return (false);
}

void Command::mode_channel(Message *msg, std::vector<std::string> message)
{
    std::cout << "je suis dans mode_channel" << std::endl;
    Server *server = msg->getserver();
    Channel *channel;
    User *user = msg->getuser();
    User *target;
    std::string mode;

    if(!(channel = server->get_channel_by_name(message[1])))
        return (send_reply(user->getFd(), user->getPrefix() + " 403 " + ERR_NOSUCHCHANNEL(message[2])));
    if (message.size() == 4)
    {
        if (!(target = server->get_user_by_nickname(message[3])))
            return (send_reply(user->getFd(), user->getPrefix() + " 401 " + ERR_NOSUCHNICK(message[3])));
        if (!channel->isUserinChannel(*target))
            return (send_reply(user->getFd(), user->getPrefix() + " 442 " + ERR_NOTONCHANNEL(message[3])));
        //change mode for the user in the channel only with map <int, string> (fd[fd de l'user], mode[+o]);
    }
    if (message.size() == 3)
    {
        mode = message[2];
        if (isvalid_mode_channel(mode) == true)
        {
            if (channel->getMode().empty() && *mode.begin() == '+')
            {
                channel->setMode(mode);
                std::cout << "MODE = " << channel->getMode() << std::endl;
            }
        }
    }
           
}

void Command::mode_user(Message *msg, std::vector<std::string> message)
{
    std::cout << "je suis dans mode_user" << std::endl;
    User *user = msg->getuser();
    std::string mode = message[2];
    //need to check if user is in the server. by doing something like:
    //Server *server = server;
    //std::cout << "MODE de l'user = " << user->getMode() << std::endl;    
    if (user->getMode().empty())
    {
        if (mode.find("+") == 0)
        {
            std::string str = "w";
            str += mode.substr(1);
            user->setMode(str);
            std::cout << "user mode = " << user->getMode() << std::endl;
            send_reply(user->getFd(),RPL_UMODEIS(user));
        }
        else
        {
            //need to set reply
            return;
        }
    }
    else
    {
        return;
    }
    return;
}

void Command::mode(Message *msg, std::vector<std::string> message)
{
    std::cout << "Je suis dans MODE" << std::endl;
    std::cout << "message[1] = " << message[1] << std::endl;
    User    *usr = msg->getuser();
    Server  *server = msg->getserver();
    (void)server;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NEEDMOREPARAMS("MODE")));
    if (message[1].find("#") != std::string::npos)
        mode_channel(msg, message);
    else
        mode_user(msg, message);
}