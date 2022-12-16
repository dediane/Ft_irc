/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:22 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 12:26:35 by ddecourt         ###   ########.fr       */
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
    
    return;
}

Command::~Command()
{
    return;
}

void Command::execute(std::string cmd, Message *msg, std::vector<std::string> message, int nb)
{
    command_ptr commands[7] = 
    {&Command::pass, &Command::nick, &Command::user, \
    &Command::mode, &Command::ping, &Command::pong, \
    &Command::join};

    std::vector<std::string>::iterator it;
    for (it = message.begin(); it < message.end(); it++)
    {
        if (*it == cmd)
        {
            (this->*(commands[nb]))(msg, message);
        }
    }
}