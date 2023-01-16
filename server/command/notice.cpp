/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:13:06 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/16 16:31:32 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::notice(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::vector<std::string>::iterator it;
    std::string buffer;
    
    if (message.size() == 1)
        return (send_reply(user->getFd(), user->getPrefix() + " 461 " + ERR_NEEDMOREPARAMS("NOTICE")));
    else if (message.size() == 2)
        return (send_reply(user->getFd(), user->getPrefix() + " 412 " + ERR_NOTEXTTOSEND()));
    else
    {
        User *receiver = NULL;
        if (server->get_user_by_nickname(message[1]) != NULL)
            receiver = server->get_user_by_nickname(message[1]);
        else
            return (send_reply(user->getFd(), user->getPrefix() + " 401 " + ERR_NOSUCHNICK(message[1])));
        buffer = user->getPrefix() + " NOTICE " + receiver->getNickname() + " :";
        for (it = message.begin() + 2; it != message.end(); ++it)
        {
            buffer += (*it) + " ";
        }
        send_reply(receiver->getFd(), buffer + END);
        std::cout << RED << "==> [NOTICE] " << BLUE << user->getNickname() << " send a message to " << receiver->getNickname() << DEFAULT << std::endl;
    }
}
