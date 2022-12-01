/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:45:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/01 19:20:58 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef User_HPP
#define User_HPP

#include "server.hpp"

class User
{
    public:
        User();
        User(int fd, std::string nickname);
        User(const User &lhs);
        ~User();
        User &operator=(const User &lhs);

        std::string getNickname();

        bool isRegistered();
        bool isOnline();
        bool isDeleted();

    private:
        std::string _nickname;
        int fd;
        bool _registered;
        bool _online;
        bool _deleted;
};

#endif