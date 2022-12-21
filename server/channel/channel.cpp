/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:55:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/21 18:00:36 by ddecourt         ###   ########.fr       */
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

Channel::Channel(User user)
{
    _users.push_back(user);
}


Channel::Channel(const Channel &lhs)
{
    _name = lhs._name;
    _topic = lhs._topic;
    _mode = lhs._mode;
    _users = lhs._users;
    return;
}

Channel &Channel::operator=(const Channel &lhs)
{
    this->_mode = lhs._mode;
    this->_name = lhs._name;
    this->_topic = lhs._topic;
    this->_users = lhs._users;
    this->_key = lhs._key;
    return (*this);
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

 void Channel::deleteUser(User user)
 {
    std::vector<User>::iterator it;
    for (it = _users.begin(); it != _users.end(); it++)
    {
        if ((*it).getNickname() == user.getNickname())
            break;
    }
    _users.erase(it);
    return;
 }

 void Channel::broadcast(std::string rpl)
 {
    std::vector<User>::iterator it;
    for (it = _users.begin(); it != _users.end(); it++)
    {
        std::cout << "BROADCAST" << std::endl;
        std::cout << "USER NAME = "<< (*it).getNickname() << std::endl;
        if (send((*it).getFd(), rpl.c_str(), rpl.length(), 0) == -1)
        std::cout << "error" << std::endl;
    }
 }

  void Channel::broadcast_msg(std::string rpl, User *user)
 {
    std::vector<User>::iterator it;
    for (it = _users.begin(); it != _users.end(); it++)
    {
        if ((*it).getFd() != user->getFd())
        {
            if (send((*it).getFd(), rpl.c_str(), rpl.length(), 0) == -1)
                std::cout << "error" << std::endl;      
        }
    }
 }

std::string Channel::getName() {return _name;}
std::string Channel::getTopic() {return _topic;}
std::string Channel::getMode() {return _mode;}
std::string Channel::getKey() {return _key;}
std::vector<User> Channel::getUsers() {return _users;}

void Channel::setName(std::string name) {_name = name; return;}
void Channel::setTopic(std::string topic) {_topic = topic; return;}
void Channel::setMode(std::string mode) {_mode = mode; return;}
void Channel::setKey(std::string key) {_key = key; return;}