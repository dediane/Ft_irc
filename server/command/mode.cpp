/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 19:59:29 by ddecourt         ###   ########.fr       */
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
    (void)message;
}

void Command::mode(Message *msg, std::vector<std::string> message)
{
    User    *usr = msg->getuser();
    Server  *server = msg->getserver();
    (void)server;
    if (message.size() == 1)
        return(send_reply(usr->getFd(), ERR_NEEDMOREPARAMS("MODE")));
    if (message[1].find("#") != std::string::npos)
        mode_channel(msg, message);
    mode_user(msg, message);
}