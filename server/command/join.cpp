/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:15:15 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/30 14:46:00 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// COMMANDE: /join #channel
// Joins the specified channel.
// example:  /join #irchelp

// This will make you join the #irchelp channel. Once on a channel, anything you type will be seen by all the users on this channel. 
// The #irchelp channel is very useful, so say hello and then ask any questions you want. 
// If the channel you specified does not exist, a channel with that name will be created for you.
// Some channels may also have keys ie. a password, which you need to specify when using the /join command.
// example:  /join #irchelp trout

//    If a JOIN is successful, the user receives a JOIN message as
//    confirmation and is then sent the channel's topic (using RPL_TOPIC) and
//    the list of users who are on the channel (using RPL_NAMREPLY), which
//    MUST include the user joining.

// This will make you join the #irchelp channel using "trout" as the password.

#include "main.hpp"


// bool is_channel_name_valide(std::string str)
// {
//     // il faut envoyer seulement le nom du chan sans ','
//     for(unsigned int i = 0; i < str.length(); ++i)
//     {
//         if (str[0] == '#' || str[0] == '&')
//             i++;
//         char c = str[i];
//         (void)c;
//         /*if (std::isalpha((int)c) || c == '_' )
//         {
//             i++;
//         }
//         else
//         {
//             std::cout << "je return false car str[i] vaut " << str[i] << std::endl;
//             return (false);
//         }*/
//     }
//     return (true);
// }

//function to get all the channels from the join command if more than one
std::vector<std::string>   parse_element(std::string str)
{
    int index = 0;
    std::string tmp;
    std::vector<std::string> channels;
    while((index = str.find(',')) != (int)std::string::npos)
    {
        tmp = str.substr(0,index);
        channels.push_back(tmp);
        str.erase(0, index + 1);
    }
    channels.push_back(str);
    return (channels);
}


void join_channel(Message *msg, std::string message, std::string key)
{
    User *user = msg->getuser();
    Server *server = msg->getserver();
    Channel *channel;

    std::vector<std::string> names = server->get_all_channels_names();
    std::vector<std::string>::iterator it;
    for (it = names.begin(); it != names.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }
    if ((channel = server->get_channel_by_name(message)) != NULL)
    {
        // check if the user is invited 
        if (channel->is_mode('i') && (!channel->isUserinvited(*user)))
            return (send_reply(user->getFd(), user->getPrefix() + " 473 " + user->getNickname() + " " +  ERR_INVITEONLYCHAN(channel->getName())));
        if (!channel->isUserinChannel(*user))
        {
            if (key == channel->getKey())
            {
                channel->addUser(*user);
                channel->addUserMode(user->getFd(), "");
                send_reply(user->getFd(), RPL_NAMREPLY(user, channel));
                send_reply(user->getFd(), RPL_ENDOFNAMES(user, channel));
                channel->broadcast(user->getPrefix() + " JOIN " + ":" + channel->getName() + END);
            }
            else
                return (send_reply(user->getFd(), user->getPrefix() + " 475 " + user->getNickname() + " " +  ERR_BADCHANNELKEY(channel->getName())));
                // then need to be change with this error:         475     ERR_BADCHANNELKEY
                //std::cout << "ERROR" << std::endl;
        }
    }
    else
    {
        std::string name = message;
        Channel new_channel(*user);
        new_channel.setName(name);
        new_channel.setKey(key);
        server->addChannel(&new_channel);
        send_reply(user->getFd(), RPL_NAMREPLY(user, &new_channel));
        send_reply(user->getFd(), RPL_ENDOFNAMES(user, &new_channel));
        send_reply(user->getFd(), user->getPrefix() + " JOIN " + ":" + new_channel.getName() + END);
    }
}

void join_many_channels(Message *msg, std::vector<std::string>channels, std::vector<std::string>keys)
{
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator it2;
    std::string key;

    it = channels.begin();
    it2 = keys.begin();
    for (unsigned int i = 0; i < channels.size(); i++)
    {
        join_channel(msg, (*it), (*it2));
        it++;
        it2++;
    }  
}

void Command::join(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    std::vector<std::string>::iterator it;
    std::vector<std::string> channels_list;
    std::vector<std::string> keys_list;
    int nb_of_channel = 0;

    if (message.size() == 1)
    {
        send_reply(user->getFd(), ERR_NEEDMOREPARAMS("JOIN"));
        return;
    }
    if (message[1].find(',') != std::string::npos)
    {
        for (it = message.begin(); it != message.end(); it++)
        {
            if (((it) == message.begin() + 1) && ((*it).find(",") != std::string::npos))
            {
                channels_list = parse_element(*it);
                nb_of_channel = channels_list.size();
            }
            if (((it) == message.begin() + 2) && ((*it).find(",") != std::string::npos))
                keys_list = parse_element(*it);
            if (nb_of_channel != 0 && message.size() == 2)
            {
                std::vector<std::string>::iterator it2;
                for (int i = 0; i < nb_of_channel; i++)
                    keys_list.push_back("x");
            }
        }
        join_many_channels(msg, channels_list, keys_list);
    }
    else
    {
        nb_of_channel = 1;
        //if (!message[2].empty()) laiser la ligne d'en dessous pck sinon ca abort avec la commande ( /join chan )
        if (message.size() == 3)
            join_channel(msg, message[1], message[2]);
        else
            join_channel(msg, message[1], "x");
    }
    // donc pour rejoindre des chan -> chan,chan,chan
    // separer par des , et des qu'il a un ' ' c'est les keys
    // pour les chan respectifs

            // -> sert a sovair si le chanel existe server->get_channel_by_name(message[1])
            //function to join many channels parsing here
            // -> check number of channel
            // -> check if channel are valid
            // -> check if channel already exist then -> check password and join success OR wrongpassword


    // creation of channel
}
