/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:49 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/30 14:31:49 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::topic(Message *msg, std::vector<std::string> message)
{   
    User *user = msg->getuser();
    Server *server = msg->getserver();
    Channel *channel;
    if (message.size() > 2)
    {
        if (!(channel = server->get_channel_by_name(message[1])))
            return(send_reply(user->getFd(), user->getPrefix() + " 403 " + ERR_NOSUCHCHANNEL(message[1])));
        if (channel->isUserinChannel(*user) == false)
            return (send_reply(user->getFd(), user->getPrefix() + " 442 " + ERR_NOTONCHANNEL(channel->getName())));
        if (message.size() == 2)
        {
            if (channel->getKey().empty() == true)
                return(send_reply(user->getFd(), RPL_NOTOPIC(user, channel)));
            else
                return(send_reply(user->getFd(), RPL_TOPIC(user, channel)));
        }
        else
        {
            if (channel->is_usermode(user->getFd(), 't') && (!(channel->getUserMode(user->getFd()).find("o") != std::string::npos)))
                return(send_reply(user->getFd(), user->getPrefix() + " 482 " + ERR_CHANOPRIVNEEDED(channel->getName())));
            else
            {
                std::vector<std::string>::iterator it;
                std::string buffer;
                for (it = message.begin() + 2; it != message.end(); it++)
                {
                    buffer += (*it) + " ";
                }
                buffer.erase(buffer.end() -1);
                channel->setTopic(buffer);
                channel->broadcast(RPL_TOPIC(user, channel));
                channel->setMode("+t");            }
        }
    }
    else
        return(send_reply(user->getFd(), ERR_NEEDMOREPARAMS("TOPIC")));
}
