/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:58:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/15 17:51:41 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

User::User()
{
    
}

User::User(int newfd, sockaddr_in address)
{
    fd = newfd;
    _registered = false;
    _online = false;
    _hostaddr = inet_ntoa(address.sin_addr); //convert host addr in a string
    fcntl(fd, F_SETFL, O_NONBLOCK);
    char buffer[NI_MAXHOST];
    if (getnameinfo((sockaddr *)&address, sizeof(address), buffer, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) == -1)
        std::cout << "error getnameinfo" << std::endl;
    _hostname = buffer;
    _cmd = new Command();
}

User::User(const User &lhs)
{
    this->fd = lhs.fd;
    this->_nickname = lhs._nickname;
    this->_hostname = lhs._hostname;
    this->_username = lhs._username;
    //this->_commands = lhs._commands;
    this->_cmd = lhs._cmd;
    this->_registered = lhs._registered;
    this->_online = lhs._online;

}

User::~User()
{
    
}

User &User::operator=(const User &lhs)
{
    this->fd = lhs.fd;
    this->_nickname = lhs._nickname;
    this->_hostname = lhs._hostname;
    this->_username = lhs._username;
    //this->_commands = lhs._commands;
    this->_cmd = lhs._cmd;
    this->_registered = lhs._registered;
    this->_online = lhs._online;
    return (*this);
}



/***********/
/*Accessors*/
/***********/

void User::setNickname(std::string nickname) {_nickname = nickname; return;}
void User::setUsername(std::string username) {_username = username; return;}
void User::setRealname(std::string realname) {_realname = realname; return;}
void User::setHostname(std::string hostname) {_hostname = hostname; return;}
void User::setHostAddr(std::string hostaddr) {_hostaddr = hostaddr; return;}
void User::setLastPing(time_t last_ping) {_last_ping = last_ping; return;}
void User::setisRegistered(bool status) {_registered = status; return;};
void User::setisOnline(bool status) {_online = status; return;};
void User::setisDeleted(bool status) {_deleted = status; return;};
void User::setisPassword(bool status) {_password = status; return;};

std::string User::getNickname() {return (_nickname);}
std::string User::getUsername() {return (_username);}
std::string User::getRealname() {return (_realname);}
std::string User::getHostname() {return (_hostname);}
std::string User::getHostAddr() {return (_hostaddr);}
std::string User::getPrefix() {return (":" + _nickname + "!" + _username + "@" + _hostname);}
int User::getFd() {return (fd);}

bool User::isRegistered() {return (_registered);}
bool User::isOnline() {return (_online);}
bool User::isDeleted() { return (_deleted);}