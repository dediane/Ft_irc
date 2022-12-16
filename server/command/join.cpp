/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:15:15 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 18:59:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// COMMANDE: /join #channel
// Joins the specified channel.
// example:  /join #irchelp

// This will make you join the #irchelp channel. Once on a channel, anything you type will be seen by all the users on this channel. 
// The #irchelp channel is very useful, so say hello and then ask any questions you want. 
// If the channel you specified does not exist, a channel with that name will be created for you.
// Some channels may also have keys ie. a password, which you need to specify when using the /join command.
// example:  /join #irchelp trout

//    If a JOIN is successful, the user receives a JOIN message as
//    confirmation and is then sent the channel's topic (using RPL_TOPIC) and
//    the list of users who are on the channel (using RPL_NAMREPLY), which
//    MUST include the user joining.

// This will make you join the #irchelp channel using "trout" as the password.

#include "main.hpp"

void Command::join(Message *msg, std::vector<std::string> message)
{
    User *user = msg->getuser();
    Server *server = msg->getserver();
    std::vector<std::string>::iterator it;
    Channel *channel;
    Channel new_channel;
    int nb_of_channel;
    if (message.size() == 1)
    {
        send_reply(user->getFd(), ERR_NEEDMOREPARAMS("PASS"));
        return;
    }
    for (it = message.begin(); it != message.end(); it++)
    {
        if ((*it).find(",") != std::string::npos)
        {
            //function to join many channels
            // -> check number of channel
            // -> check if channel are valid
            // -> check if channel already exist then -> check password and join success OR wrongpassword
        }
        else
            nb_of_channel = 1;
    }
    std::cout << "JOIN 56: Je passe là" << std::endl;
    if (nb_of_channel == 1)
    {
        if ((channel = server->get_channel_by_name(message[1])) != NULL)
        {
            std::cout << "JOIN 60: Je ne passe bien pas là" << std::endl;
            if (!channel->isUserinChannel(*user))
                channel->addUser(*user);
        }
        else
        {
            std::cout << "JOIN 67: Je passe là" << std::endl;
            std::string name = message[1];
            new_channel.setName(name);
            new_channel.addUser(*user);
            //std::cout << 
            server->addChannel(&new_channel);
        }
    }
}