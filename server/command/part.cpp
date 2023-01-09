/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:30:10 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/09 15:14:33 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to leave a channel

#include "main.hpp"

void Command::part(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    Channel *channel;
    Server *server = msg->getserver();
    //:diane!diane@localhost PART #lolo[2022-12-20 21:47:49]
    // if (message.size() == 1)
    // {
    //     send_reply(user->getFd(), ERR_NEEDMOREPARAMS("PART"));
    //     return;
    // }
    //  std::vector<std::string>::iterator it = message.begin();
    // for (; it != message.end(); it++)
    // {
    //     std::cout << "notre message est -> " << *(it) << std::endl;
    // }
    if ((channel = server->get_channel_by_name(message[1])) != NULL)
    {
        if (channel->isUserinChannel(*user))
        {
            send_reply(user->getFd(), user->getPrefix() + " PART " + channel->getName() + END);
            channel->broadcast_msg(user->getPrefix() + " PART " + channel->getName() + END, user);
            //channel->removeUserMode(user->getFd());
            channel->deleteUser(*user);
        }
    }
    std::cout << RED << "==> [PART] " << CYAN << "User " << user->getNickname() << " part from the channel " << DEFAULT << std::endl;   
}