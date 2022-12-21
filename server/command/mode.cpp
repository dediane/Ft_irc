/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/21 14:34:13 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//User modes
// - [o] - User is an operator (prefix @).
// - [w] - User receives wallops;
// - [r] - restricted user connection.


//Channel modes
// [O] - give "channel creator" status;
// [o] - give/take channel operator privilege;
// [v] - give/take the voice privilege;

// [a] - toggle the anonymous channel flag;
// [i] - toggle the invite-only channel flag;
// [m] - toggle the moderated channel;
// [n] - toggle the no messages to channel from clients on the outside;
// [q] - toggle the quiet channel flag;
// [p] - toggle the private channel flag;
// [s] - toggle the secret channel flag;
// [r] - toggle the server reop channel flag;
// [t] - toggle the topic settable by channel operator only flag;

// [k] - set/remove the channel key (password);
// [l] - set/remove the user limit to channel;

// [b] - set/remove ban mask to keep users out;
// [e] - set/remove an exception mask to override a ban mask;
// [I] - set/remove an invitation mask to automatically override the invite-only flag;

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
    std::string mode = message[2];
    //need to check if user is in the server. by doing something like:
    //Server *server = server;
    std::cout << "MODE de l'user = " << user->getMode() << std::endl;    
    if (user->getMode().empty())
    {
        if (mode.find("+") == 0)
        {
            std::string str = "w";
            str += mode.substr(1);
            user->setMode(str);
            std::cout << "user mode = " << user->getMode() << std::endl;
            send_reply(user->getFd(),RPL_UMODEIS(user));
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
    std::cout << "Je suis dans MODE" << std::endl;
    std::cout << "message[1] = " << message[1] << std::endl;
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