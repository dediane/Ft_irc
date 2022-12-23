/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:18:58 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <algorithm>

void Command::whois(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    std::cout << "Je suis dans WHOIS" << std::endl;
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::vector<std::string> users = server->get_all_nicknames();
    std::vector<std::string>::iterator it = std::find(users.begin(), users.end(),  message[1]);
    if (it != users.end())
    {
        User * user2 = server->get_user_by_nickname(message[1]);
        if (user2)
            send_reply(user->getFd(),   user2->getNickname() + " " + user2->getUsername() + " " + user2->getHostname() + " " + "*" + " :" +  user2->getRealname()  + END); //311  RPL_WHOISUSER // "<nick> <user> <host> * :<real name>"
        send_reply(user->getFd(), user->getNickname() + " " + server->getCreationTime() + END);// 312    RPL_WHOISSERVER // "<nick> <server> :<server info>" //autres infos du serveur a mettre en avant ?
        if (user2->getMode() == "+o") //a verifier apres qu'on s'occupe des operators
            send_reply(user->getFd(), user2->getNickname() + " :is an IRC operator" + END);  // 313    RPL_WHOISOPERATOR // "<nick> :is an IRC operator"
    }
}