/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:07:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/24 16:26:20 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

    #include "main.hpp"

    class User;
    class Server;

    std::string RPL_WELCOME(User user);
    std::string RPL_YOURHOST(User user);
    std::string RPL_CREATED(User user, std::string time);
    std::string RPL_UMODEIS(User *user);
    std::string RPL_NAMREPLY(User *user, Channel *channel);
    std::string RPL_ENDOFNAMES(User *user, Channel *channel);
    std::string RPL_TOPIC(User *user, Channel *channel);
    std::string RPL_NOTOPIC(User *user, Channel *channel);
    std::string RPL_INVITING(User *user, Channel *channel, std::string nick);
    std::string RPL_WHOISUSER(User *user); //311  RPL_WHOISUSER // "<nick> <user> <host> * :<real name>"
    std::string RPL_WHOISSERVER(User *user);
    std::string RPL_WHOISOPERATOR(User *user);
    std::string RPL_LIST(Channel chan, std::string clientcount);
    std::string RPL_LISTEND();
    std::string RPL_CHANNELMODEIS(User *user, Channel *channel);
    std::string reply(User user, Server server, int num);
    void send_reply(int fd, std::string rpl);
#endif
