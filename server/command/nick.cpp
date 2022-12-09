/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:46 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 13:55:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::nick(Message *msg, std::vector<std::string> message)
{
    User *usr = msg->getuser();
    Server *server = msg->getserver();
    (void) server;
    (void)message;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NONICKNAMEGIVEN(usr->getNickname())));
    std::string nickname = message[1];
    if (nickname.length() > 9)
        return(send_reply(usr->getFd(), ERR_ERRONEUSNICKNAME(nickname)));
    usr->setNickname(nickname);
} 