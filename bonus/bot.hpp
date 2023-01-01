/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:45:32 by parallels         #+#    #+#             */
/*   Updated: 2022/12/31 17:10:01 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BOT_HPP
# define BOT_HPP

# include <csignal>
# include <cctype>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <unistd.h>
# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
class Bot
{
	private:
		int			sockfd;
		int			port;
		int			hostname;
		std::string	channel;
		std::string	nick;
		std::string	bot_name;
    	struct sockaddr_in address;
	
	public:
		Bot();
		Bot(Bot &rhs);
		Bot(int Port, int Hostname, std::string Channel, std::string Nick);
		Bot &operator=(Bot &rhs);
		~Bot();

		int				getPort(void);
		int				getHostname(void);
		std::string		getChannel(void);
		std::string		getNick(void);
		
		void	setPort(int Port);
		void	setHostname(int hostname);
		void	setChannel(std::string Channel);
		void	setNick(std::string Nick);

		void	init();
		void	connect_to_serv();
};

void    ft_exit(std::string str);


# endif