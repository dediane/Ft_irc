/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:16 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/08 18:12:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "main.hpp"

class Command
{
    public:
        Command();
        ~Command();
        std::vector<std::string> _commandlist;
        void execute(std::string cmd, User user, std::vector<std::string> message, int nb);

        void pass(User user, std::vector<std::string> message);
        void nick(User user, std::vector<std::string> message);
        void user(User user, std::vector<std::string> message);

    private:
};

typedef void (Command::*command_ptr)(User user, std::vector<std::string> message);

#endif