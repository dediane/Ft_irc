/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:46:55 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/29 17:24:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "main.hpp"

class User;
class Channel
{
    friend class User;
    
    public:
        Channel();
        Channel(std::string name, User user);
        Channel(const Channel &lhs);
        Channel &operator=(const Channel &lhs);
        Channel(User user);
        ~Channel();
        
        void broadcast(std::string rpl);
        void broadcast_msg(std::string rpl, User *user);
        //getter
        std::string getName();
        std::string getTopic();
        std::string getMode();
        std::string getKey();
        std::vector<User> getUsers();
        std::string getUserMode(int fd);

        bool is_mode(char x);
        bool is_usermode(int fd, char x);

        //setter
        void setName(std::string name);         
        void setTopic(std::string topic);         
        void setMode(std::string mode);
        void setKey(std::string key);


        //helper
        bool isUserinChannel(User user);
        bool isUserinvited(User user);
        void addUser(User user);
        void addUserInvited(User user);
        void addUserMode(int fd, std::string mode);
        void removeUserMode(int fd);
        void deleteUser(User user);
        void RemoveUserFromChan(User user);
        User *get_user(User *user);

    private:
        std::string _name;
        std::string _topic;
        std::string _mode;
        std::string _key;
        std::vector<User> _users;
        std::vector<User> _users_invited;
        std::map<int, std::string> _users_mode;
        
        
};

#endif