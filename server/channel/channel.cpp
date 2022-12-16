/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:55:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 18:38:57 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "channel.hpp"


Channel::Channel()
{
    return;
}

Channel::Channel(std::string name, User user)
{
    _name = name;
    _users.push_back(user);
}

Channel::Channel(Channel &lhs)
{
    _name = lhs._name;
    _topic = lhs._topic;
    _mode = lhs._mode;
    _users = lhs._users;
    return;
}

Channel::~Channel()
{
    return;
}

bool Channel::isUserinChannel(User user)
{
    std::vector<User>::iterator it;
    for (it = _users.begin(); it != _users.end(); it++)
    {
        if (user.getNickname() == (*it).getNickname())
            return true;
    }
    return false;
}

 void Channel::addUser(User user)
 {
    _users.push_back(user);
    return;
 }

std::string Channel::getName() {return _name;}
std::string Channel::getTopic() {return _topic;}
std::string Channel::getMode() {return _mode;}
std::string Channel::getKey() {return _key;}

void Channel::setName(std::string name) {_name = name; return;}
void Channel::setTopic(std::string topic) {_topic = topic; return;}
void Channel::setMode(std::string mode) {_mode = mode; return;}
void Channel::setKey(std::string key) {_key = key; return;}