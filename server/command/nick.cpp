/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:46 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/07 16:22:25 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::nick(Message *msg, std::vector<std::string> message)
{
    User *usr = msg->getuser();
    Server *server = msg->getserver();
    std::string oldnick;
    std::vector<std::string> nicknames = server->get_all_nicknames();
    (void) server;
    (void)message;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NONICKNAMEGIVEN(usr->getNickname())));
    std::string nickname = message[1];
    if (nickname.length() > 9)
        return(send_reply(usr->getFd(), ERR_ERRONEUSNICKNAME(nickname)));
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator ite;
    for (it = nicknames.begin(); it != nicknames.end(); it++)
    {
        if ((*it) == nickname)
        {
            for (ite = nicknames.begin(); ite != nicknames.end(); ite++)
            {
                if (*ite == nickname + "_")
                    nickname += "_";
            }
            usr->setNickname(nickname + "_");
            return(send_reply(usr->getFd(), ERR_NICKNAMEINUSE(nickname)));
        }
    }
    oldnick = usr->getNickname();
    usr->setNickname(nickname);
    if (usr->isRegistered())
    {
        send_reply(usr->getFd(),":" + oldnick + "!" + usr->getUsername() + "@" + usr->getHostname() + " NICK :" + usr->getNickname() + END);
        std::cout << RED << "==> [NICK] " << BLUE << oldnick << " change his nickname to " << usr->getNickname() << DEFAULT << std::endl;
    }
} 