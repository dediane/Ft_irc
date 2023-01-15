/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:21 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/15 16:07:44 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /quit [message]
//Disconnects from current server with optional leaving message.
#include "main.hpp"

void Command::quit(Message *msg, std::vector<std::string> message)
{
    std::string buffer;
    User *user = msg->getuser();
    // Server *server = msg->getserver();
    std::vector<std::string>::iterator it;
    for (it = message.begin(); it != message.end(); ++it)
        std::cout << "in quit -> =" << (*it) << std::endl;
    if (message.size() == 1)
        std::cout << RED << "==> [QUIT] " << user->getNickname() << " quit the server ;_;" << DEFAULT << std::endl;
    else
    {
        for (it = message.begin() + 1; it != message.end(); ++it)
            buffer += (*it);
        std::cout << RED << "==> [QUIT] " << user->getNickname() << " quit the server ;_; because of " << buffer  << DEFAULT << std::endl;
    }
    user->setisOnline(false);
    //server->remove_user(user);
    // user->RemoveUserFromChans(*user);
    //manager si il y a un message
}