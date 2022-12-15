/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/15 23:59:59 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//User modes
// +q
// User is owner of the current channel (prefix ~ on UnrealIRCd, usually @ elsewhere)
// +a
// User is an admin (SOP) on the current channel (prefix & on UnrealIRCd, usually @ elsewhere).
// +o
// User is an operator (AOP) on the current channel (prefix @).
// +h
// User is a half-op on the current channel (prefix %).
// +v
// User has voice on the current channel (prefix +).

void Command::mode_channel(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
}

void Command::mode_user(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    std::cout << "je suis dans mode_user" << std::endl;
    if (message.size() == 0)
        return;
    User *user = msg->getuser();
    std::string str = message[2];
    std::cout << "message[2]" << str << std::endl;
    //need to check if user is in the server. by doing something like:
    //Server *server = server;    
    if (user->getMode().empty())
    {
        if (str.find("+") == 0)
        {
            str = str.substr(1);
            user->setMode(str);
            std::cout << "user mode = " << user->getMode() << std::endl;
            send_reply(user->getFd(),RPL_UMODEIS(*user));
        }
        else
        {
            //need to set reply
            return;
        }
    }
    else
    {
        return;
    }
    return;
}

void Command::mode(Message *msg, std::vector<std::string> message)
{
    User    *usr = msg->getuser();
    Server  *server = msg->getserver();
    (void)server;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NEEDMOREPARAMS("MODE")));
    if (message[1] != usr->getNickname())
        return; //need to add error rply
    if (message[1].find("#") != std::string::npos)
        mode_channel(msg, message);
    mode_user(msg, message);
}