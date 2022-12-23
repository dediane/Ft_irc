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
        send_reply(user->getFd(), RPL_YOURHOST(*user) + RPL_WHOISSERVER(user));
        if (user2->getMode() == "+o") //a verifier apres qu'on s'occupe des operators
            send_reply(user->getFd(), RPL_WHOISSERVER(user2));
    }
}