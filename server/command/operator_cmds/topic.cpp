/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:49 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/26 13:40:35 by ddecourt         ###   ########.fr       */
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
        {
            std::cout << "CHANNEL NAME " << channel->getName() << std::endl;
            return(send_reply(user->getFd(), ERR_NOSUCHCHANNEL(message[1])));
        }
        if (channel->isUserinChannel(*user) == false)
        {
            return (send_reply(user->getFd(), ERR_NOTONCHANNEL(channel->getName())));
        }
        if (message.size() == 2)
        {
            if (channel->getKey().empty() == false)
                return(send_reply(user->getFd(), RPL_NOTOPIC(user, channel)));
            else
                return(send_reply(user->getFd(), RPL_TOPIC(user, channel)));
        }
        else
        {
            std::string mode = user->getMode();
            //if (mode.find("o") != std::string::npos)
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
    }
    else
        return(send_reply(user->getFd(), ERR_NEEDMOREPARAMS("TOPIC")));
}
