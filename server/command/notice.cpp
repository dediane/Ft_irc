/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:13:06 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/20 00:19:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Command::notice(Message *msg, std::vector<std::string> message)
{
        (void)msg;
    (void)message;
    std::cout << "Je passe dans la commande NOTICE" << std::endl;

    return;
}
