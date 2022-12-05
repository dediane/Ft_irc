/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:07:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/05 14:10:40 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

    #include "main.hpp"

    class User;
    class Server;

    std::string RPL_WELCOME(User user);
    std::string RPL_YOURHOST(User user);
    std::string RPL_CREATED(User user, std::string time);
#endif
