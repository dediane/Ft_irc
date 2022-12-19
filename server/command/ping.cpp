/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:16:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/19 13:41:47 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::ping(Message *msg, std::vector<std::string> message)
{
    //std::cout << "Je suis dans ping" << std::endl;
    std::cout << message.size() <<std::endl;
    User *user = msg->getuser();
    if (message.size() == 1)
        return;
    (void)user;
    send_reply(user->getFd(), "PONG :" + message[1] + END);
}