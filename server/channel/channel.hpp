/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:46:55 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/18 22:02:10 by ddecourt         ###   ########.fr       */
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
        Channel(User user);
        ~Channel();
        
         void broadcast(std::string rpl);
        //getter
        std::string getName();
        std::string getTopic();
        std::string getMode();
        std::string getKey();

        //setter
        void setName(std::string name);         
        void setTopic(std::string topic);         
        void setMode(std::string mode);
        void setKey(std::string key);


        //helper
        bool isUserinChannel(User user);
        void addUser(User user);

    private:
        std::string _name;
        std::string _topic;
        std::string _mode;
        std::string _key;
        std::vector<User> _users;
        
        
};

#endif