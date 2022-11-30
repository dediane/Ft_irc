/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:45:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 19:02:08 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef User_HPP
#define User_HPP

class User
{
    public:
        User();
        User(User &lhs);
        ~User();
    private:
        std::string _nickname;
        unsigned int fd;
        
};

#endif