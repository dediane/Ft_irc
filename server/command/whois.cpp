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
    std::cout << "MESSAGE SIZE IS : " << message.size() << std::endl;
    std::vector<std::string>::iterator it;
    for (it  = message.begin(); it != message.end(); it++ )
            std::cout << " ==== " << *it << std::endl;
(void)server;
   
        // std::cout << "REAL NAME IS " <<  user->getUsername() << std::endl;
        // std::vector<std::string>::iterator it = std::find(users.begin(), users.end(),  message[2]);
        // if (it != users.end())
        //     send_reply(user->getFd(),   user->getNickname() + " " + user->getUsername() + " " + user->getHostname() + " " + "*" + " :" + user->getRealname()  + END); //311,


    std::cout << "REAL NAME IS " <<  user->getUsername() << std::endl;
    std::vector<std::string> users = server->get_all_nicknames();
    std::cout << "SEARCHING FOR " << message[1] << std::endl;
        std::vector<std::string>::iterator it2 = std::find(users.begin(), users.end(),  message[1]);
        if (it2 != users.end())
        {
            std::cout << "J AI TROUVE " << std::endl;
            User * user2 = server->get_user_by_nickname(message[1]);
            // send_reply(user->getFd(),   user->getNickname() + " " + user->getUsername() + " " + user->getHostname() + " " + "*" + " :" + user->getRealname()  + END); //311,
            if (user2)
                send_reply(user->getFd(),   user2->getNickname() + " " + user2->getUsername() + " " + user2->getHostname() + " " + "*" + " :" +  user2->getRealname()  + END); //311,

        } // "<nick> <user> <host> * :<real name>"

            // send_reply(user->getFd(),   (*it).getNickname() + " " + (*it).getUsername() + " " + (*it).getHostname() + " " + "*" + " :" + (*it).getRealname()  + END); //311,
//     RPL_WHOISUSER::RPL_WHOISUSER(Peer &peer, const Peer &target, bool include_prefix) : Message(peer, std::string())

    // else if ((message.size() == 2))
    // {
    //     // std::vector<std::string> users =  server->getUsers();
    //     std::vector<std::string> users = server->get_all_nicknames();
    //     std::vector<std::string>::iterator it = std::find(users.begin(), users.end(),  message[2]);
    //     if (it != users.end())
    //     {
    //         std::cout << "REAL NAME IS " << *it << std::endl;
    //         send_reply(user->getFd(), user->getPrefix() + " WHOIS " +  (*it) + END); 
            
    //         //PRINT  (*it).getUsername()
    //          //RPL_WHO"<nick> <user> <host> * :<real name>"
    //         // 311    RPL_WHOISUSER
    //     }

    //     // std::map<int, User> users =  server->getUsers();
    //     // std::map<int, User>::iterator it = users.find(message[2]);
    //     // if (it != users.end())
    //     // {
    //     //     send_reply(user->getFd(), user->getPrefix() + " WHOIS " +  (*it).getUsername() + END); 
    //     //     //PRINT  (*it).getUsername()
    //     //      //RPL_WHO"<nick> <user> <host> * :<real name>"
    //     //     // 311    RPL_WHOISUSER
    //     // }

    // }

   
    // "<nick> <user> <host> * :<real name>"
    // 312    RPL_WHOISSERVER
    // "<nick> <server> :<server info>"
    // 313    RPL_WHOISOPERATOR
    // "<nick> :is an IRC operator"


}