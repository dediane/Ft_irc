/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:21 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/13 15:34:18 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /quit [message]
//Disconnects from current server with optional leaving message.
#include "main.hpp"

void Command::quit(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    // Server *server = msg->getserver(); see line 34
    std::string buff = "";

    user->setisOnline(false);
    std::cout << RED << "==> [QUIT] " << user->getNickname() << " quit the server ;_;" << DEFAULT << std::endl;
    if (message.size() == 1)
        send_reply(user->getFd(), "QUIT :leaving\r\n");
    else
    {
        std::vector<std::string>::iterator it;
        for (it = message.begin(); it != message.end(); it++)
            buff += (*it);
        send_reply(user->getFd(), "QUIT :leaving for reason " + buff + "\r\n");
    }
    // server->remove_user(user); we cannot use this function because heap-use-after-free
    // the user is delete in this function but because we dosen't fix the heartbeat managment
    // and we have to erase the pollfd of this user in fds (in server.cpp)
}