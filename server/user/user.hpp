/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:45:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/03 00:05:15 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef User_HPP
#define User_HPP

#include "server.hpp"

class Server;
class User
{
    friend class Server;
    public:
        User();
        User(int fd, sockaddr_in address);
        User(const User &lhs);
        ~User();
        User &operator=(const User &lhs);

        void setNickname(std::string nickname);
        void setUsername(std::string username);
        void setRealname(std::string realname);
        void setHostname(std::string hostname);
        void setHostAddr(std::string hostaddr);
        void setLastPing(time_t last_ping);

        std::string getNickname();
        std::string getUsername();
        std::string getRealname();
        std::string getHostname();
        std::string getHostAddr();
        time_t      getLastPing();
        

        bool isRegistered();
        bool isOnline();
        bool isDeleted();
        bool isPassword();

        void receive(Server *server);



    private:
        int             fd;
        time_t          _last_ping;
    
        std::string     _nickname;
        std::string     _username;
        std::string     _realname;
        std::string     _hostname;
        std::string     _hostaddr;
        std::string     _mode;
 
        
        
        bool _registered;
        bool _online;
        bool _deleted;
        bool _password;

        std::string user_buffer;

};

#endif