/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:06 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/08 20:37:29 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


//User modes
// +q
// User is owner of the current channel (prefix ~ on UnrealIRCd, usually @ elsewhere)
// +a
// User is an admin (SOP) on the current channel (prefix & on UnrealIRCd, usually @ elsewhere).
// +o
// User is an operator (AOP) on the current channel (prefix @).
// +h
// User is a half-op on the current channel (prefix %).
// +v
// User has voice on the current channel (prefix +).

void Command::user(User user, std::vector<std::string> message)
{
    (void)user;
    (void)message;
    std::cout << "I am user function" << std::endl;
}