/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:21 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/07 16:05:25 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /quit [message]
//Disconnects from current server with optional leaving message.
#include "main.hpp"

void Command::quit(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    User *user = msg->getuser();

    user->setisOnline(false);
    // user->RemoveUserFromChans(*user);

    //manager si il y a un message
    std::cout << RED << "==> [QUIT] " << user->getNickname() << " quit the server ;_;" << DEFAULT << std::endl;
}