/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:09 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/23 16:28:06 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::pass(Message *msg, std::vector<std::string> message)
{
    std::vector<std::string>::iterator it;
    std::cout << "Je passe dans la commande PASS" << std::endl;
    
    for (it = message.begin(); it != message.end(); it++)
        std::cout << (*it) << std::endl;
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::string serverPassword = server->getPassword();

    // (void)message;
    // if (message.size() == 1)
    if (message.size() < 2)
        return(send_reply(user->getFd(), ERR_NEEDMOREPARAMS(message[0])));
    if (message[1] != serverPassword)
    {
        user->setisOnline(false);
        return(send_reply(user->getFd(), ERR_PASSWDMISMATCH()));
    }
    if (message[1] == serverPassword)
        user->setisPassword(true);
}
