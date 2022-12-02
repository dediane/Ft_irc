/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:58:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/02 17:06:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

User::User()
{
    
}

User::User(int fd, std::string nickname)
{
    this->_nickname = nickname;
    this->fd = fd;
}

User::User(const User &lhs)
{
    this->_nickname = lhs._nickname;
    this->fd = lhs.fd;
}

User::~User()
{
    
}


User &User::operator=(const User &lhs)
{
    this->_nickname = lhs._nickname;
    this->fd = lhs.fd;
    return (*this);
}

void User::receive(Server *server)
{
    std::string end = END;
    char buffer[BUFFER_SIZE + 1];
    
    ssize_t response_size = recv(server->sockfd, &buffer, BUFFER_SIZE, 0);
    std::cout << response_size << std::endl;
    if (response_size == -1)
        return;
    if (response_size == 0)
    {
        //end of socket stream or zero byte received
        return;
    }
    buffer[response_size] = 0;
    user_buffer = user_buffer + buffer;
    
    std::cout << user_buffer << std::endl;
}

/***********/
/*Accessors*/
/***********/

std::string User::getNickname() {return (_nickname);}

bool User::isRegistered() {return (_registered);}

bool User::isOnline() {return (_online);}

bool User::isDeleted() { return (_deleted);}