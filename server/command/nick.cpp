/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:46 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/08 20:22:10 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::nick(User user, std::vector<std::string> message)
{
    (void)user;
    (void)message;
    if (message.size() == 1)
        return(send_reply(user.getFd(), ERR_NONICKNAMEGIVEN(user.getNickname())));
    std::string nickname = message[1];
    if (nickname.length() > 9)
        return(send_reply(user.getFd(), ERR_ERRONEUSNICKNAME(nickname)));
    user.setNickname(nickname);
    
    std::cout << "I am nick function" << std::endl;
}