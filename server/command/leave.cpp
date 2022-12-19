/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:30:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:19:20 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to leave a channel

#include "main.hpp"

void Command::leave(Message *msg, std::vector<std::string> message)
{
        (void)msg;
    (void)message;
    std::cout << "Je passe dans la commande LEAVE" << std::endl;
    
}

