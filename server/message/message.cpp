/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:31 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 13:52:57 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Message::Message()
{
    
}

Message::Message(User *user, Server *server)
{
    _user = user;
    _server = server;
}

Message::Message(Message &lhs)
{
    (void)lhs;
}

Message::~Message()
{
    
}

Server  *Message::getserver() { return _server; }
User    *Message::getuser() { return _user; }

void Message::receive_msg()
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t response_size = recv(_user->getFd(), buffer, BUFFER_SIZE, 0);
    if (response_size == -1)
        return;
    //std::cout << buffer << std::endl;
    //std::cout << response_size << std::endl;
    if (response_size == 0)
        return;
    buffer[response_size] = 0;
    msg_buffer = msg_buffer + buffer;
    //std::cout << user_buffer << std::endl;
    split_buffer(msg_buffer);
    std::vector<std::string>::iterator it;
    for (it = _messages.begin(); it != _messages.end(); it++)
        parse_commands(*it);
}

void Message::split_buffer(std::string str)
{
    std::string tofind = "\r\n";
    int index = 0;
    while ((index = str.find(tofind, index)) != (int)(std::string::npos)) 
    {
        std::string tmp;
        for(int i = 0; i < index; i++)
            tmp.push_back(str[i]);
        _messages.push_back(tmp);
        tmp.clear();
        index += tofind.length();
        str.erase(0, index);
        index = 0;
    }
    std::vector<std::string>::iterator it;
    // for (it = _messages.begin(); it != _messages.end(); it++)
    //     std::cout << *it; 
    return;
}

void Message::parse_commands(std::string str)
{
    int index = 0;
    std::vector<std::string> commands;
    while((index = str.find(" ", index)) != (int)std::string::npos)
    {
        commands.push_back(str.substr(0, index));
        str.erase(0, index + 1);
    }
    commands.push_back(str);
    std::vector<std::string>::iterator it;
    index = 0;
    for (it = commands.begin(); it != commands.end(); it++)
    {
        if (it == commands.begin())
        {
            std::vector<std::string>::iterator it2;
            for (it2 = _user->_cmd->_commandlist.begin(); it2 != _user->_cmd->_commandlist.end(); it2++)
            {
                if (*it == *it2)
                {
                    //std::cout << "command = " << *it2 << std::endl;
                    _user->_cmd->execute(*it, this, commands, index);
                    if (_user->isRegistered())
                    {
                        std::cout << "Nickname = " << _user->getNickname() << std::endl;
                        std::cout << "Username = " << _user->getUsername() << std::endl;
                        std::cout << "Realname = " << _user->getRealname() << std::endl;
                        std::cout << "Hostname = " << _user->getHostname() << std::endl;
                        _user->do_handshake();
                    }
                }
                index++;
            }
        }
        else
            std::cout << *it << std::endl; 
    }
}
