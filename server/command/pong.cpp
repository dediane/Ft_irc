/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:17:10 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 02:00:31 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <ctime>

void Command::pong(Message *msg, std::vector<std::string> message)
{
    //std::cout << "je suis dans pong" << std::endl;
    User *user = msg->getuser();
    Server *server = msg->getserver();
    if (message.size() == 1)
        return;
    user->setLastPing(std::time(0));
    server->setLastping(std::time(0));
    // send_reply(user->getFd(), "PING :" + message[1] + END);
}