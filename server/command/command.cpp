/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:22 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/06 23:59:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"

Command::Command()
{
    _commandlist.push_back("PASS");
    _commandlist.push_back("NICK");
    _commandlist.push_back("USER");
    return;
}

Command::~Command()
{
    return;
}