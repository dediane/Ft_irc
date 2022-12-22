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

    // if (message.size() == 1 ) // a remettre en reglant le probleme doing this is not a good idea                       // || (message.size() == 2  && ((message[1]) == "-YES")   a enlever quand doing this is not a good idea disparaitra. je sais pas dou vient cette obligation -YES. fonction fonctionnait avant ce msg d'erreur
    // {
        std::vector<Channel>::iterator it;
        for (it = channels->begin(); it != channels->end(); it++)
        {
            //  RPL_LIST (322) 
            //   "<client> <channel> <client count> :<topic>"
            int a = (*it).getUsers().size();
            std::stringstream ss;
            ss << a;
            std::cout << "Dans le chan " << (*it).getName() << "Il y a " << a << " Users et le topic est " << (*it).getTopic() << std::endl;
            std::string clientcount = ss.str();
            send_reply(user->getFd(), user->getPrefix()  + " LIST " + (*it).getName() + " " + clientcount/* client count */ + " :" + (*it).getTopic() + END); 
           //egalement verifier quand on aura les topics set. 
           
            //RPL LIST END difference ? 
        }
        //}
    if (!(message[1]).empty()) //pour tester il faut d'abord regler le pb de doing this is not a good idea car sinon pas le bon nombre de params et ne peut entrer ici
    {
        //If the <channel> parameter is used, only the status of that channel is displayed.
        std::vector<std::string>all_channels_asked = ft_split(message[1], ",");
        std::vector<std::string>::iterator it3;
        for(it3 = all_channels_asked.begin(); it3 != all_channels_asked.end(); it3++)  //itere sur chaque channel
        {
            std::vector<std::string> channel_names =  server->get_all_channels_names();
            // std::vector<std::string>::iterator it2 = channel_names.find(it3); //it3 correspond a mon channel
            std::vector<std::string>::iterator it2 = std::find(channel_names.begin(), channel_names.end(),  *it3); //it3 correspond a mon channel
            if (it2 != channel_names.end())
                send_reply(user->getFd(), user->getPrefix() + " LIST " + /*    (*it).getStatus()    */ + END); 
        }


        //  If the <target> parameter is specified, the request is forwarded to that server which will generate the reply.    Wildcards are allowed in the <target> parameter. on ne doit pas gerer les multiserveurs sauf erreur

    }
  
}


//    Numeric Replies:

//            ERR_TOOMANYMATCHES              ERR_NOSUCHSERVER
//            RPL_LIST                        RPL_LISTEND
 

//  RPL_LIST (322) 
//   "<client> <channel> <client count> :<topic>"
// Sent as a reply to the LIST command, this numeric sends information about a channel to the client. <channel> is the name of the channel. <client count> is an integer indicating how many clients are joined to that channel. <topic> is the channel’s topic (as set by the TOPIC command).

// RPL_LISTEND (323) 
//   "<client> :End of /LIST"
// Sent as a reply to the LIST command, this numeric indicates the end of a LIST response.
// ERR_NOSUCHSERVER (402) 
//   "<client> <server name> :No such server"
// Indicates that the given server name does not exist. The text used in the last param of this message may vary.
    



/*

      Command: LIST
   Parameters: [ <channel> *( "," <channel> ) [ <target> ] ]

   The list command is used to list channels and their topics.  If the
   <channel> parameter is used, only the status of that channel is
   displayed.

   If the <target> parameter is specified, the request is forwarded to
   that server which will generate the reply.

   Wildcards are allowed in the <target> parameter.

   Numeric Replies:

           ERR_TOOMANYMATCHES              ERR_NOSUCHSERVER
           RPL_LIST                        RPL_LISTEND

   Examples:

   LIST                            ; Command to list all channels.

   LIST #twilight_zone,#42         ; Command to list channels
                                   #twilight_zone and #42



*/