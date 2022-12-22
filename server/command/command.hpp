/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:16 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/22 14:25:14 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "main.hpp"

class Message;
class Command
{
    public:
        Command();
        ~Command();
        std::vector<std::string> _commandlist;
        void execute(std::string cmd, Message *msg, std::vector<std::string> message, int nb);

        void pass(Message *msg, std::vector<std::string> message);
        void nick(Message *msg, std::vector<std::string> message);
        void user(Message *msg, std::vector<std::string> message);
        void mode(Message *msg, std::vector<std::string> message);
        void ping(Message *msg, std::vector<std::string> message);
        void pong(Message *msg, std::vector<std::string> message);
        void join(Message *msg, std::vector<std::string> message);
        void quit(Message *msg, std::vector<std::string> message);
        void whois(Message *msg, std::vector<std::string> message);
        void privmsg(Message *msg, std::vector<std::string> message);
        void list(Message *msg, std::vector<std::string> message);
        void part(Message *msg, std::vector<std::string> message);
        void notice(Message *msg, std::vector<std::string> message);
        void topic(Message *msg, std::vector<std::string> message);
        void mode_channel(Message *msg, std::vector<std::string> message);
        void mode_user(Message *msg, std::vector<std::string> message);

    private:
        //User *user;
        //Server *server;
};

typedef void (Command::*command_ptr)(Message *msg, std::vector<std::string> message);

#endif