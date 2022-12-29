/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:55:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/29 17:25:08 by ddecourt         ###   ########.fr       */
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
    user.setNickname("@" + user.getNickname());
    _users.push_back(user);
    _mode = "+n";
    _users_mode.insert(std::pair<int, std::string>(user.getFd(), "+o"));
}

Channel::Channel(User user)
{
    user.setNickname("@" + user.getNickname());
    _users.push_back(user);
    _mode = "+n";
    _users_mode.insert(std::pair<int, std::string>(user.getFd(), "+o"));
}


Channel::Channel(const Channel &lhs)
{
    _name = lhs._name;
    _topic = lhs._topic;
    _mode = lhs._mode;
    _users = lhs._users;
    _key = lhs._key;
    _users_mode = lhs._users_mode;
    return;
}

Channel &Channel::operator=(const Channel &lhs)
{
    this->_mode = lhs._mode;
    this->_name = lhs._name;
    this->_topic = lhs._topic;
    this->_users = lhs._users;
    this->_key = lhs._key;
    this->_users_mode = lhs._users_mode;
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
    for (it = _users.begin(); it != _users.end(); it++)
    {
        if ("@" + user.getNickname() == (*it).getNickname())
            return true;
    }
    
    
    return false;
}

bool Channel::isUserinvited(User user)
{
    std::vector<User>::iterator it;
    for (it = _users_invited.begin(); it != _users_invited.end(); it++)
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

void Channel::addUserInvited(User user)
{
    _users_invited.push_back(user);
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

void Channel::addUserMode(int fd, std::string mode)
{
    _users_mode.insert(std::pair<int, std::string>(fd, mode));
}

void Channel::removeUserMode(int fd)
{
    _users_mode.erase(_users_mode.find(fd));
}

User *Channel::get_user(User *user)
{
    std::vector<User>::iterator it;
    for (it = _users.begin(); it != _users.end(); it++)
    {
        if((*it).getFd() == user->getFd()) 
        {    
            return &(*(it));
        }
    }
    return NULL;
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
std::string Channel::getUserMode(int fd) {return  (_users_mode.find(fd))->second;}

bool Channel::is_mode(char x)
{
    if (this->getMode().find(x) != std::string::npos)
        return true;
    return false;
}

bool Channel::is_usermode(int fd, char x)
{
    if (this->getUserMode(fd).find(x) != std::string::npos)
        return true;
    return false;
}

void Channel::setName(std::string name) {_name = name; return;}
void Channel::setTopic(std::string topic) {_topic = topic; return;}
void Channel::setMode(std::string mode) {_mode = mode; return;}
void Channel::setKey(std::string key) {_key = key; return;}

void    Channel::RemoveUserFromChan(User user)
{
    if (isUserinChannel(user) == true)
        deleteUser(user);

    // Server server;
    // Channel channels = server.get_all_channels();
    // std::vector<Channel> *channel = server.get_all_channels();
    // std::vector<Channel>::iterator it; 
    // for(it = channel->begin(); it != channel->end(); it++)
    // {
    //     if ((*it).isUserinChannel(user) == true)
    //     {
    //         std::cout << "User name = " << user.getNickname() << std::endl;
    //         (*it).deleteUser(user);

    //     }
    // }
}