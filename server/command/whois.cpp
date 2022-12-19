/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:18:58 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::whois(Message *msg, std::vector<std::string> message)
{
    (void)msg;
    (void)message;
    std::cout << "Je suis dans WHOIS" << std::endl;
}