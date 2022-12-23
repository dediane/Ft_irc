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
#include "main.hpp"

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
            send_reply(user->getFd(), RPL_WHOISUSER(user2));
        send_reply(user->getFd(), RPL_WHOISSERVER(user));
        if (user2->getMode() == "+o") //a verifier apres qu'on s'occupe des operators
            send_reply(user->getFd(), RPL_WHOISSERVER(user2));
    }
    // reply(User user, Server server, int num)
}

// std::string RPL_WHOISUSER(User user) //311  RPL_WHOISUSER // "<nick> <user> <host> * :<real name>"
// {
//     std::string buffer =  user.getNickname() + " " + user.getUsername() + " " + user.getHostname() + " " + "*" + " :" +  user.getRealname()  + END;
//     return buffer;
// }

// std::string RPL_WHOISSERVER(User user)
// {
//     Server server;
//     std::string buffer = user.getNickname() + " " + server.getCreationTime() + END;// 312    RPL_WHOISSERVER // "<nick> <server> :<server info>" //autres infos du serveur a mettre en avant ?
//     return buffer;
// }

// std::string RPL_WHOISOPERATOR(User user) //313  RPL_WHOISOPERATOR // "<nick> <user> <host> * :<real name>"
// {
//     std::string buffer =  user.getNickname() + " :is an IRC operator" + END;
//     return buffer;
// }