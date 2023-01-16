/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:39 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/16 11:47:17 by bben-yaa         ###   ########.fr       */
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

        int receive_msg();
        void split_buffer(std::string str);
        void parse_commands(std::string str);
        void do_handshake();
        User    *getuser();
        Server  *getserver();
        void setuser(User *user);

        std::vector<std::string> get_split(std::string input, std::string separater);
        std::vector<std::string> getTokens(std::string cmd);
        void make_uppercase(std::string &token);
        void print_tokens(std::vector<std::string>  tokens);
        void replacerbyn(std::string &input);

    private:
       User *_user;
       Server *_server;

        std::string msg_buffer;
        bool cmd;
        std::string command;
        std::vector<std::string> _messages;
};

#endif