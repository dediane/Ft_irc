/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:06 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/21 14:42:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::user(Message *msg, std::vector<std::string> message)
{
    std::cout << "Je passe dans la commande USER" << std::endl;
    User *user = msg->getuser();
    // (void)message;
    // std::cout << "I am user function" << std::endl;
    if (message.size() < 5)
        return(send_reply(user->getFd(), ERR_NEEDMOREPARAMS(message[0])));
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
        user->setisRegistered(true);
        msg->do_handshake();
    //    user->setisOnline(true);
    }
}