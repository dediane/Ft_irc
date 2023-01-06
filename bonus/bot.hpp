/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:45:32 by parallels         #+#    #+#             */
/*   Updated: 2023/01/04 17:18:59 by parallels        ###   ########.fr       */
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
# include <netdb.h>

void    ft_exit(std::string str);

class Bot
{
	private:
		int			sockfd;
		int			port;
		std::string	hostname;
		std::string	channel;
		std::string	nick;
		std::string	bot_name;
		
	
	public:
		Bot();
		Bot(Bot &rhs);
		Bot(int Port, std::string Hostname, std::string Channel, std::string Nick);
		Bot &operator=(Bot &rhs);
		~Bot();

		int				getPort(void);
		std::string		getHostname(void);
		std::string		getChannel(void);
		std::string		getNick(void);
		
		void	setPort(int Port);
		void	setHostname(std::string hostname);
		void	setChannel(std::string Channel);
		void	setNick(std::string Nick);

		void	init(int port, char *hostname, char *channel, char *nick);
		void	connect_to_serv(void);
		void	run(void);
		void	send_msg(std::string msg); // don't forget to add  msg += "\r\n"
		void	receve_msg(void);
};



# endif