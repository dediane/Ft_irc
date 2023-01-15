/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:22 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/15 16:07:21 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"

Command::Command()
{
    _commandlist.push_back("PASS");
    _commandlist.push_back("NICK");
    _commandlist.push_back("USER");
    _commandlist.push_back("MODE");
    _commandlist.push_back("PING");
    _commandlist.push_back("PONG");
    _commandlist.push_back("JOIN");
    _commandlist.push_back("QUIT");
    _commandlist.push_back("WHOIS");
    _commandlist.push_back("PRIVMSG");
    _commandlist.push_back("LIST");
    _commandlist.push_back("PART");
    _commandlist.push_back("NOTICE");
    _commandlist.push_back("TOPIC");
    _commandlist.push_back("INVITE");
    _commandlist.push_back("KICK");
    
    return;
}

Command::~Command()
{
    return;
}

void Command::execute(std::string cmd, Message *msg, std::vector<std::string> message, int nb)
{
    command_ptr commands[16] = 
    {&Command::pass, &Command::nick, &Command::user, \
    &Command::mode, &Command::ping, &Command::pong, \
    &Command::join, &Command::quit, &Command::whois, \
    &Command::privmsg, &Command::list, &Command::part, \
    &Command::notice, &Command::topic, &Command::invite, \
    &Command::kick };

    std::vector<std::string>::iterator it;
    for (it = message.begin(); it < message.end(); ++it)
    {
        if (*it == cmd)
        {
            (this->*(commands[nb]))(msg, message);
        }
    }
}