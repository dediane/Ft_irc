/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:15:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/06 15:52:17 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"

std::string RPL_WELCOME(User user)
{
    std::string buffer = user.getPrefix() +  " 001 " + user.getNickname() + " :Welcome to the Internet Relay Network" + END;
    return buffer;
}

std::string RPL_YOURHOST(User user)
{   
    std::cout << "H: " << user.getHostname() << std::endl;
    std::string buffer = user.getPrefix() +  " 002 " + user.getNickname() + " :Your host is " + user.getHostname() + ", running version 1.0" + END;
    return buffer;
}

std::string RPL_CREATED(User user, std::string time)
{
    std::string buffer = user.getPrefix() +  " 003 " + user.getNickname() + " :This server was created " + time + END;
    return buffer;
}

std::string RPL_MYINFO(User user)
{
    std::string buffer = user.getPrefix() + "004" + user.getNickname() + " :";
    return buffer;
}



std::string reply(User user, Server server, int num)
{
    switch(num)
    {
        case 001:
            return(RPL_WELCOME(user));
        case 002:
            return(RPL_YOURHOST(user));
        case 003:
            return(RPL_CREATED(user, server.getCreationTime()));
        case 004:
            return(RPL_MYINFO(user));
        default:
            return NULL;
    }
}