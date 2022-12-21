/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:13:06 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/21 16:26:16 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::notice(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::vector<std::string>::iterator it;
    std::string buffer;
    if (!message[1].empty())
    {
        User *receiver = NULL;
        if (server->get_user_by_nickname(message[1]) != NULL)
            receiver = server->get_user_by_nickname(message[1]);
        else
            return;
        std::cout << "receiver = " << receiver->getNickname() << std::endl;
        buffer = user->getPrefix() + " NOTICE " + receiver->getNickname() + " ";
        for (it = message.begin() + 2; it != message.end(); it++)
        {
            buffer += (*it) + " ";
        }
        std::cout << "BUFFER = " << buffer << std::endl;
        send_reply(receiver->getFd(), buffer + END);
        //:toto!ddecourt@localhost NOTICE lola :Salut Lola
    }
        
        std::cout << "Je passe dans la commande NOTICE" << std::endl;

    return;
}
