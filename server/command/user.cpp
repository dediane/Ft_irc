/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:06 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/16 15:21:39 by bben-yaa         ###   ########.fr       */
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
        return (send_reply(user->getFd(), user->getPrefix() + " 464 " + ERR_PASSWDMISMATCH()));
    if (user->getNickname() == "")
        return(send_reply(user->getFd(), user->getPrefix() + " 431 " + ERR_NONICKNAMEGIVEN(user->getNickname())));
    user->setUsername(message[1]);
    user->setHostname(message[3]);
    user->setRealname(message[4]);
    if (!user->isRegistered())
    {
        std::cout << GREEN << "==> " <<  user->getNickname() << " is registered" << DEFAULT << std::endl;
        user->setisRegistered(true);
        msg->do_handshake();
        user->setisOnline(true);
    }    
}