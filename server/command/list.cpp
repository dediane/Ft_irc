/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:44 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/07 16:24:18 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::list(Message *msg, std::vector<std::string> message)
{
        (void)msg;
    (void)message;
    // msg->print_tokens(message);
    Server *server = msg->getserver();
    User *user = msg->getuser();
    std::vector<Channel> * channels = server->get_all_channels();

    if ((message.size() == 1))
    {
        std::vector<Channel>::iterator it;
        for (it = channels->begin(); it != channels->end(); it++)
        {
            int a = (*it).getUsers().size();
            std::stringstream ss;
            ss << a;
            std::string clientcount = ss.str();
            send_reply(user->getFd(), RPL_LIST(*it, clientcount));
        }
        send_reply(user->getFd(), RPL_LISTEND()); //egalement verifier quand on aura les topics set. 
    }
    else
    {
        //If the <channel> parameter is used, only the status of that channel is displayed.
        std::vector<std::string>all_channels_asked = msg->get_split(message[1], ",");
        std::vector<std::string>::iterator it3;
        for(it3 = all_channels_asked.begin(); it3 != all_channels_asked.end(); it3++)  //itere sur chaque channel
        {
            std::cout << "Channel ===" << *it3 << std::endl;
            std::vector<std::string> channel_names =  server->get_all_channels_names();
            std::vector<std::string>::iterator it2 = std::find(channel_names.begin(), channel_names.end(),  *it3); //it3 correspond a mon channel
            if (it2 != channel_names.end())
                send_reply(user->getFd(), user->getPrefix() + " LIST " + /*    (*it).getStatus()    */ + END); 
        }
    }
    std::cout << RED << "==> [LIST] " << BLUE << " command list called" << DEFAULT << std::endl;
}