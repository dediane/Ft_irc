/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:49 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/23 16:45:05 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::topic(Message *msg, std::vector<std::string> message)
{   
    User *user = msg->getuser();
    Server *server = msg->getserver();
    Channel *channel = server->get_channel_by_name(user->getLastChannel());
    if (!channel)
    {
        send_reply(user->getFd(), ERR_NOTONCHANNEL(""));
        return;
    }
    if (channel->isUserinChannel(*user) == false)
    {
        send_reply(user->getFd(), ERR_NOTONCHANNEL(channel->getName()));
        return;
    }
        
    std::string user_mode = user->getMode();
    if (message.size() == 1)
    {
        return;
    }
    if (message.size() > 1)
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
    }
}
