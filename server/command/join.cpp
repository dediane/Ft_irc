/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:15:15 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 15:58:19 by ddecourt         ###   ########.fr       */
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
        std::vector<std::string> names = server->get_all_channels_names();
        std::vector<std::string>::iterator it;
        for (it = names.begin(); it != names.end(); it++)
        {
            std::cout << (*it) << std::endl;
        }
        if ((channel = server->get_channel_by_name(message[1])) != NULL)
        {
            std::cout << "JOIN 60: Je ne passe bien pas là" << std::endl;
            if (!channel->isUserinChannel(*user))
            {
                channel->addUser(*user);
                channel->broadcast(user->getPrefix() + " JOIN " + ":" + channel->getName() + END);
                 send_reply(user->getFd(), RPL_NAMREPLY(user, channel));
                 send_reply(user->getFd(), RPL_ENDOFNAMES(user, channel));
                //send_reply(user->getFd(), user->getPrefix() + " JOIN " + ":" + channel->getName() + END);
            }
        }
        else
        {
            std::cout << "JOIN 67: Je passe là" << std::endl;
            std::string name = message[1];
            Channel new_channel(*user);
            new_channel.setName(name);
            server->addChannel(&new_channel);
            send_reply(user->getFd(), RPL_NAMREPLY(user, &new_channel));
            send_reply(user->getFd(), RPL_ENDOFNAMES(user, &new_channel));
            send_reply(user->getFd(), user->getPrefix() + " JOIN " + ":" + new_channel.getName() + END);
            
            //std::cout << 

            // ==> JOIN #toto
            // <== :diane!diane@localhost 353 diane = #toto :@diane
            // <== :diane!diane@localhost 366 diane #toto :End of /NAMES list
            // <== :diane!diane@localhost JOIN :#toto
            // ==> MODE #toto
            // <== :diane!diane@localhost 324 diane #toto +n
            // ==> WHO #toto
            // <== :diane!diane@localhost 315 diane diane :End of /WHO list
        }
    }
}