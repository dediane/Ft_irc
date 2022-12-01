/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:58:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/01 19:21:43 by ddecourt         ###   ########.fr       */
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

/***********/
/*Accessors*/
/***********/

std::string User::getNickname() {return (_nickname);}

bool User::isRegistered() {return (_registered);}

bool User::isOnline() {return (_online);}

bool User::isDeleted() { return (_deleted);}