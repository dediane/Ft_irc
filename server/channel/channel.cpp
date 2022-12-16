/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:55:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 15:39:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "channel.hpp"

Channel::Channel()
{
    return;
}

Channel::Channel(Channel &lhs)
{
    return;
}

Channel::~Channel()
{
    return;
}

std::string Channel::getName() {return _name;}
std::string Channel::getTopic() {return _topic;}
std::string Channel::getMode() {return _mode;}

void Channel::setName(std::string name) {_name = name; return;}
void Channel::setTopic(std::string topic) {_topic = topic; return;}
void Channel::setMode(std::string mode) {_mode = mode; return;}