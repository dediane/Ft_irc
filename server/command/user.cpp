/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:06 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 17:00:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::user(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    // (void)message;
    // std::cout << "I am user function" << std::endl;
    if (message.size() != 5)
        return(send_reply(user->getFd(), ERR_NEEDMOREPARAMS(message[0])));
    user->setUsername(message[1]);
    user->setHostname(message[3]);
    user->setRealname(message[4]);
    if (!user->isRegistered())
    {
        user->setisRegistered(true);
        msg->do_handshake();
    }
}