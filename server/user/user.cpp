/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:58:37 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/15 19:38:06 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

User::User()
{
    _last_ping = time(0);
    fd = 0;
    _nickname = "NULL";
    _username = "NULL";
    _realname = "NULL";
    _hostname = "NULL";
    _hostaddr = "NULL";
    _mode = "NULL";
    _registered = false;
    _online =  true;
    _deleted = false;
    _password = false;
}

User::User(int newfd, sockaddr_in address)
{
    _nickname = "NULL";
    _username = "NULL";
    _realname = "NULL";
    _hostname = "NULL";
    _hostaddr = "NULL";
    _mode = "NULL"; 
    fd = newfd;
    _last_ping = time(0);
    _registered = false;
    _online = true;
    _hostaddr = inet_ntoa(address.sin_addr); //convert host addr in a string
    fcntl(fd, F_SETFL, O_NONBLOCK);
    char buffer[NI_MAXHOST];
    if (getnameinfo((sockaddr *)&address, sizeof(address), buffer, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) == -1)
        std::cout << "error getnameinfo" << std::endl;
    _hostname = buffer;
    _mode = "+w";
    _cmd = new Command();
    _nickname = "NULL";
    _username = "NULL";
    _realname = "NULL";
    _mode = "NULL";
    _deleted = false;
    _password = false;
}

User::User(const User &lhs)
{
    this->fd = lhs.fd;
    this->_nickname = lhs._nickname;
    this->_hostname = lhs._hostname;
    this->_username = lhs._username;
    this->_mode = lhs._mode;
    //this->_commands = lhs._commands;
    this->_cmd = lhs._cmd;
    this->_registered = lhs._registered;
    this->_online = lhs._online;
    this->_last_ping = lhs._last_ping;

}

User::~User()
{
    return;
}

User &User::operator=(const User &lhs)
{
    this->fd = lhs.fd;
    this->_nickname = lhs._nickname;
    this->_hostname = lhs._hostname;
    this->_username = lhs._username;
    this->_mode = lhs._mode;
    //this->_commands = lhs._commands;
    this->_cmd = lhs._cmd;
    this->_registered = lhs._registered;
    this->_online = lhs._online;
    this->_last_ping = lhs._last_ping;

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
void User::setMode(std::string mode) {_mode = mode; return;}
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
std::string User::getMode() {return (_mode);}
std::string User::getPrefix() {return (":" + _nickname + "!" + _username + "@" + _hostname);}
time_t      User::getLastPing() {return (_last_ping);};
int User::getFd() {return (fd);}

bool User::isRegistered() {return (_registered);}
bool User::isOnline() {return (_online);}
bool User::isDeleted() {return (_deleted);}
bool User::isPassword() {return (_password);};

bool User::is_mode(char x)
{
    if (this->getMode().find(x) != std::string::npos)
        return true;
    return false;
}



