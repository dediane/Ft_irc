/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:30:10 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 21:53:00 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to leave a channel

#include "main.hpp"

void Command::part(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    User *user = msg->getuser();
    //:diane!diane@localhost PART #lolo[2022-12-20 21:47:49]
    if (message.size() == 1)
    {
        send_reply(user->getFd(), ERR_NEEDMOREPARAMS("PART"));
        return;
    }
    
    std::cout << "Je passe dans la commande PART" << std::endl;
    
}