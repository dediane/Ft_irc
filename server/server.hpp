/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/07 00:12:34 by ddecourt         ###   ########.fr       */
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

        public:
            Server();
            Server(Server &lhs);
            ~Server();
        

            void init();
            void execute();
            void accept_new_user();
            void do_handshake(int fd, User user);
            User get_user_by_fd(int user_fd);

            std::string getCreationTime()
            {
                std::stringstream t;
                t << creation;
                std::string ts = t.str();
                return ts;
            };
    };

#endif