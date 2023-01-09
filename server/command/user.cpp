/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:06 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/09 15:01:24 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::user(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();

    if (message.size() < 5)
        return(send_reply(user->getFd(), user->getPrefix() + " 461 " + ERR_NEEDMOREPARAMS(message[0])));
    if (user->isOnline() == false)
        return ;
    if (!user->isPassword())
        return (send_reply(user->getFd(), user->getPrefix() + " 462 " + ERR_ALREADYREGISTRED()));
    user->setUsername(message[1]);
    user->setHostname(message[3]);
    user->setRealname(message[4]);
    // std::cout << "User Register on FD" << user->getFd() << " Username: " << message[1] << "Host: " << message[3] << " Real: " << message[4] << std::endl;
    // for (int i = 0; i < 5; i++)
    //   std::cout << message[i] << std::endl;
    // std::cout << "user fd = " << user->getFd() << std::endl;
    // std::cout << "is registered? " << user->isRegistered() << std::endl;
    if (!user->isRegistered())
    {
        std::cout << GREEN << "==> " <<  user->getNickname() << " is registered" << DEFAULT << std::endl;
        user->setisRegistered(true);
        msg->do_handshake();
        user->setisOnline(true);
    }    
}