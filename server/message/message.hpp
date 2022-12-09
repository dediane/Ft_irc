/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:39 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 16:51:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "main.hpp"

class Message
{
    friend class Server;
    friend class User;
    public:
        Message();
        Message(User *user, Server *server);
        Message(Message &lhs);
        ~Message();

        void receive_msg();
        void split_buffer(std::string str);
        void parse_commands(std::string str);
        void do_handshake();
        User    *getuser();
        Server  *getserver();
    private:
       User *_user;
       Server *_server;

        std::string msg_buffer;
        bool cmd;
        std::string command;
        std::vector<std::string> _messages;
};

#endif