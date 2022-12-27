/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:15:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/27 13:12:17 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "server.hpp"



std::string RPL_WELCOME(User user)
{
    std::string buffer = user.getPrefix() +  " 001 " + user.getNickname() + " :Welcome to the Internet Relay Network " + user.getNickname() + "!" + user.getUsername() + "@" + user.getHostname() + END;
    //std::cout << buffer << std::endl;
    return buffer;
}

std::string RPL_YOURHOST(User user)
{   
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
    std::string buffer = user.getPrefix() + "004" + user.getNickname() + " :" + END;
    return buffer;
}

std::string RPL_UMODEIS(User *user)
{
    std::cout << user->getMode() << std::endl;
    std::string buffer = user->getPrefix() + " 221 " + user->getNickname() + " " + user->getMode() + END;
    return buffer;
}

std::string RPL_NAMREPLY(User *user, Channel *channel)
{
    std::vector<User> users;
    std::vector<User>::iterator it;
    users = channel->getUsers();
    std::string buffer = user->getPrefix() + " 353 " + user->getNickname() + " = " + channel->getName();
    
    for (it = users.begin(); it != users.end(); it++)
    {
        if ((*it).getNickname() != user->getNickname())
            buffer += (" :" + (*it).getNickname());
    }
    buffer += END;
    return buffer;
}

std::string RPL_ENDOFNAMES(User *user, Channel *channel)
{
    std::string buffer = user->getPrefix() + " 366 " + user->getNickname() + " " + channel->getName() + " :End of /NAMES list" + END;
    return (buffer);
}

std::string RPL_NOTOPIC(User *user, Channel *channel)
{
    std::string buffer = user->getPrefix() + " 331 " + user->getNickname() + " " + channel->getName() + " :No topic is set" + END;
    return (buffer);
}

std::string RPL_TOPIC(User *user, Channel *channel)
{
    std::string buffer = user->getPrefix() + " TOPIC " +
    channel->getName() + " " + channel->getTopic() + END;
    return (buffer);
}

std::string RPL_INVITING(User *user, Channel *channel, std::string nick)
{
    std::string buffer = user->getPrefix() + " 341 " + channel->getName() + " " + user->getNickname() + " " + nick + END;
    return (buffer);  
}

std::string RPL_CHANNELMODEIS(User *user, Channel *channel)
{
    std::string buffer = user->getPrefix() + " 324 " + user->getNickname() + " " + channel->getName() + " " + channel->getMode() + END;
    return(buffer);
}

void send_reply(int fd, std::string rpl)
{ 
    std::cout << "SEND reply = " << rpl << std::endl;
    if (send(fd, rpl.c_str(), rpl.length(), 0) == -1)
        std::cout << "error" << std::endl;
}

/**
 * WHO IS
 * */ 
std::string RPL_WHOISUSER(User *user) //311  RPL_WHOISUSER // "<nick> <user> <host> * :<real name>"
{
    std::string buffer =  user->getNickname() + " " + user->getUsername() + " " + user->getHostname() + " " + "*" + " :" +  user->getRealname()  + END;
    return buffer;
}

std::string RPL_WHOISSERVER(User *user)
{
    Server server;
    std::string buffer = user->getNickname() + " " + server.getCreationTime() + END;// 312    RPL_WHOISSERVER // "<nick> <server> :<server info>" //autres infos du serveur a mettre en avant ?
    return buffer;
}

std::string RPL_WHOISOPERATOR(User *user) //313  RPL_WHOISOPERATOR // "<nick> <user> <host> * :<real name>"
{
    std::string buffer =  user->getNickname() + " :is an IRC operator" + END;
    return buffer;
}
/*-------*/
/*
LIST
*/

std::string RPL_LIST(Channel chan, std::string clientcount)  //  RPL_LIST (322) //   "<client> <channel> <client count> :<topic>" || 322    RPL_LIST "<channel> <# visible> :<topic>"
{
    std::string buffer =  chan.getName() + " " + clientcount +  " :" + chan.getTopic()  + END; 
    return buffer;
}

std::string  RPL_LISTEND() //323    RPL_LISTEND  ":End of LIST"  /* If there are no channels available to return, only the end reply MUST be sent.*/
{
  std::string buffer =   ":End of LIST\r\n"; 
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