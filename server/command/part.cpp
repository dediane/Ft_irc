/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:30:10 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/13 17:00:46 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to leave a channel

#include "main.hpp"

void Command::part(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    Channel *channel;
    Server *server = msg->getserver();

    if (message.size() == 1)
    {
        send_reply(user->getFd(), ERR_NEEDMOREPARAMS("PART"));
        return ;
    }
    if ((channel = server->get_channel_by_name(message[1])) != NULL)
    {
        if (channel->isUserinChannel(*user))
        {
            /*std::vector<User>::iterator it;
            std::vector<User> users;
            std::string mode = "+o";
            std::string new_mode;
            if (channel->getUserMode(user->getFd()).find("o") != std::string::npos && channel->usr_size() > 1)
            {
                users = channel->getUsers();
                for (it = users.begin(); it != users.end(); it++)
                {
                    if ((*it).getFd() != user->getFd())
                    {
                        std::cout << "ici for op" << std::endl;
                        (*it).setMode(new_mode = addmode(mode, (*it).getMode()));
                        if (mode.find('o'))
                        {  
                            (*it).setMode(deletemode("o", (*it).getMode()));                        
                            channel->addUserMode((*it).getFd(), new_mode);
                        }
                        break ;
                    }
                }
            }*/
            send_reply(user->getFd(), user->getPrefix() + " PART " + channel->getName() + END);
            channel->broadcast_msg(user->getPrefix() + " PART " + channel->getName() + END, user);
            //channel->removeUserMode(user->getFd());
            channel->deleteUser(*user);
            std::cout << RED << "==> [PART] " << CYAN << "User " << user->getNickname() << " part from the channel " << DEFAULT << std::endl;   
            return ;
        }
        return (send_reply(user->getFd(), user->getPrefix() + " 441 " + ERR_USERNOTINCHANNEL(user->getNickname(), message[1])));
    }
    return (send_reply(user->getFd(), user->getPrefix() + " 403 " + ERR_NOSUCHCHANNEL(message[1])));
}