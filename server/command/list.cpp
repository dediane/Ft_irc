/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:44 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:19:16 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


std::vector<std::string> ft_split(std::string input, std::string separater) {

	std::vector<std::string> tokens;
	size_t prev = 0;
	size_t current = input.find(separater, prev);

	while (current != std::string::npos){
		if(current - prev > 0)
			tokens.push_back(input.substr(prev, current - prev));
		prev = current + 1;
		while(input[prev] == separater[0])
			prev++;
		current = input.find(separater, prev);
	}
	if(prev < input.length())
		tokens.push_back(input.substr(prev, input.length()));
    return tokens;
}

//23:36 -!- Irssi: Doing this is not a good idea. Add -YES  option to command if you really mean it  
// https://www.rfc-editor.org/rfc/rfc2812#section-3.2.6
#include <algorithm> //pour le std find de mon vector
void Command::list(Message *msg, std::vector<std::string> message)
{
        (void)msg;
    (void)message;
    std::cout << "Je passe dans la commande LIST" << std::endl;
    Server *server = msg->getserver();
    User *user = msg->getuser();

    std::vector<Channel> * channels = server->get_all_channels();
    if ((message.size() == 1))
    {
        std::vector<Channel>::iterator it;
        for (it = channels->begin(); it != channels->end(); it++)
        {
            int a = (*it).getUsers().size();
            std::stringstream ss;
            ss << a;
            std::string clientcount = ss.str();
            send_reply(user->getFd(), RPL_LIST(*it, clientcount));
        }
        send_reply(user->getFd(), RPL_LISTEND()); //egalement verifier quand on aura les topics set. 
    }
    else
    {
        //If the <channel> parameter is used, only the status of that channel is displayed.
        std::vector<std::string>all_channels_asked = ft_split(message[1], ",");
        std::vector<std::string>::iterator it3;
        for(it3 = all_channels_asked.begin(); it3 != all_channels_asked.end(); it3++)  //itere sur chaque channel
        {
            std::cout << "Channel ===" << *it3 << std::endl;
            std::vector<std::string> channel_names =  server->get_all_channels_names();
            std::vector<std::string>::iterator it2 = std::find(channel_names.begin(), channel_names.end(),  *it3); //it3 correspond a mon channel
            if (it2 != channel_names.end())
                send_reply(user->getFd(), user->getPrefix() + " LIST " + /*    (*it).getStatus()    */ + END); 
        }
    }
}