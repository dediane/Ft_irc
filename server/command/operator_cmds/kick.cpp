/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:10 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/07 16:41:34 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// COMMANDE: /kick #channel nickname
// Kicks a nickname off a channel that you are on.
# include "main.hpp"

void Command::kick(Message *msg, std::vector<std::string> message)
{
	User *user = msg->getuser();
	Channel *channel;
	Server *server = msg->getserver();
    std::vector<std::string> nicknames = server->get_all_nicknames();
	User *user_kick;

	if (message.size() < 3)
		return ;	// protection
	
	//check si user exist
	if (server->get_user_by_nickname(message[2]) != NULL)
        user_kick = server->get_user_by_nickname(message[2]);
	else
	{
   		send_reply(user->getFd(), user->getPrefix() + " 441 " + user->getNickname() + " " + ERR_USERNOTINCHANNEL(message[2], " "));
		return ;
	}
	// check le message a envoyer à irssi
	if ((channel = server->get_channel_by_name(message[1])))
	{
		// check si le user kick est operator
		if (!(channel->getUserMode(user->getFd()).find("o") != std::string::npos))
			return ; // message error here canno't kick

		if (channel->isUserinChannel(*user) && (channel->isUserinChannel(*user_kick)))
		{
			// send to irssi ->KICK #chan toto :(no reason)
			send_reply(user_kick->getFd(), "KICK " + message[1] + " " + message[2] + " :(no reason)" + END);
			channel->broadcast_msg(user->getPrefix() + " KICK " + channel->getName() + END, user);
			channel->deleteUser(*user_kick);
        	std::cout << RED << "==> [KICK] " << BLUE << user->getNickname() << " kicked " << user_kick->getNickname() << " from channel " << channel->getName() << DEFAULT << std::endl;

		}
	}
}
//operator command