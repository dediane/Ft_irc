/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/21 23:11:55 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "main.hpp"

    class Channel;
    class User;
    class Server
    {
        friend class User;
        friend class Channel;

        public:
            Server();
            Server(const Server &lhs);
            ~Server();
        

            void init(int port);
            void execute();
            void accept_new_user();
            void do_handshake(int fd, User user);
            void heartbeat_management(int timeout, int now);
            User *get_user_by_fd(int user_fd);
            User *get_user_by_nickname(std::string nickname);
            std::vector<std::string> get_all_nicknames();
            std::vector<Channel> *get_all_channels();
            std::vector<std::string> get_all_channels_names(); //ICI
            std::string getCreationTime();
            Channel *get_channel_by_name(std::string str);
            void addChannel(Channel *channel);
            void setLastping(time_t time);
            void remove_user(User *user);
            void remove_pollfd(User *user);
        
            
        private:
            //We don't need it cause it is in <poll.h>
            // struct pollfd 
            // {
            //     int   fd;         /* file descriptor */
            //     short events;     /* requested events */
            //     short revents;    /* returned events */
            // };
            
            time_t last_ping;
            time_t heartbeat;
            time_t creation;
            
            int _port;
            int sockfd;
            
            std::vector<pollfd> fds;
            std::vector<Channel> channels; //contains all channels
            std::map<int, User> users; //contains all users as pair of: fd of the user and the user 
    };

#endif