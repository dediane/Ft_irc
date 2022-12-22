/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:49 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/22 17:29:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::topic(Message *msg, std::vector<std::string> message)
{
    //need to check if  
    (void)message;
    User *user = msg->getuser();
    std::string user_mode = user->getMode();
    
    if (user_mode.find("o"))
    {
        return;

        //461 ERR_NEEDMOREPARAMS
        //ERR_NOTONCHANNEL
                // 442     ERR_NOTONCHANNEL
                //         "<channel> :You're not on that channel"

                // - Returned by the server whenever a client tries to
                //   perform a channel effecting command for which the
                //   client isn't a member.
        //ERR_CHANOPRIVSNEEDED
        //RPL_NOTOPIC
        //RPL_TOPIC
    }
}