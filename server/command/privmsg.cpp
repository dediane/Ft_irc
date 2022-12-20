/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:27:00 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 19:33:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::privmsg(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    //(void)message;

    
    Channel *channel;
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator it2;
    std::vector<std::string> channels_names = server->get_all_channels_names();
    std::string channel_name;
    std::string buffer;
    //unsigned int pos = 0;
    for (it = message.begin(); it != message.end(); it++)
    {
        for(it2 = channels_names.begin(); it2 != channels_names.end(); it2++)
        {
            if ((*it).find(*it2) != std::string::npos)
            {
                channel_name = (*it).substr(0, (*it2).length());
                (*it).erase(0, ((*it2).length() + 1));
                std::cout << "valeur de *it = " << (*it) << std::endl;
                std::cout << "Channel name = " << channel_name << std:: endl;
                channel = server->get_channel_by_name(channel_name);
                std::cout << "channel copy name = " << channel->getName() << std::endl;
                //:diane!diane@localhost PRIVMSG #lolo :Bonjour
            }
        }
        buffer += (*it) + " ";
    }
    buffer.erase(0, 9);
    channel->broadcast_msg(user->getPrefix() + " PRIVMSG " + channel_name + " " + buffer + END, user);

    // if (*tmp.begin() == '#')
    // {
    //     std::cout << "send message in channel, need to broadcast" << std::endl;
    //     channel = server->get_channel_by_name(*tmp);
    //     //channel = server->get_channel_by_name(tmp);
    //     //std::cout << "channel name = " << channel->getName() << std::endl;
    // }
    std::cout << "Je passe dans la commande PRIVMSG" << std::endl;
    
}