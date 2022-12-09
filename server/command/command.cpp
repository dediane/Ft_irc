/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:22 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 17:25:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"

Command::Command()
{
    _commandlist.push_back("PASS");
    _commandlist.push_back("NICK");
    _commandlist.push_back("USER");
    _commandlist.push_back("MODE");
    
    return;
}

Command::~Command()
{
    return;
}

void Command::execute(std::string cmd, Message *msg, std::vector<std::string> message, int nb)
{
    command_ptr commands[20] = {&Command::pass, &Command::nick, &Command::user, &Command::mode};

    std::vector<std::string>::iterator it;
    for (it = message.begin(); it < message.end(); it++)
    {
        if (*it == cmd)
        {
            (this->*(commands[nb]))(msg, message);
        }
    }
}