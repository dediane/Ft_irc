/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:46:55 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/16 15:40:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "main.hpp"

class Channel
{
    public:
        Channel();
        Channel(Channel &lhs);
        ~Channel();
        
        //getter
        std::string getName();
        std::string getTopic();
        std::string getMode();

        //setter
        void setName(std::string name);         
        void setTopic(std::string topic);         
        void setMode(std::string mode);

        //helper
        //bool isUserinChannel(std::vector<User> all_users);

    private:
        std::string _name;
        std::string _topic;
        std::string _mode;
        std::vector<User> _users;
        
        
};

#endif