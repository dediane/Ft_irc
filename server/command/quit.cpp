/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:21 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:18:23 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /quit [message]
//Disconnects from current server with optional leaving message.
#include "main.hpp"

void Command::quit(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    std::cout << "Je passe dans la commande QUIT" << std::endl;
}