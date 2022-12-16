/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:15:15 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 12:25:09 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// COMMANDE: /join #channel
// Joins the specified channel.
// example:  /join #irchelp

// This will make you join the #irchelp channel. Once on a channel, anything you type will be seen by all the users on this channel. 
// The #irchelp channel is very useful, so say hello and then ask any questions you want. 
// If the channel you specified does not exist, a channel with that name will be created for you.
// Some channels may also have keys ie. a password, which you need to specify when using the /join command.
// example:  /join #irchelp trout

// This will make you join the #irchelp channel using "trout" as the password.

#include "main.hpp"

void Command::join(Message *msg, std::vector<std::string> message)
{
    
}