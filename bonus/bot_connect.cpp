/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_connect.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:49:08 by parallels         #+#    #+#             */
/*   Updated: 2022/12/31 17:09:41 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bot.hpp"
# include "../server/server.hpp"

bool check_port(std::string port)
{
	for (unsigned long i = 0; i < port.size(); i++)
	{
		if (port[i] < '0' || port[i] > '9')
			return false;
	}
	return true;
}

int main (int argc, char **argv)
{
	Bot bot;
	int port;
	if (argc == 5)
	{   // chek port and Hostname
		std::cout << "before port " << argv[2] << std::endl;
		if (!check_port(argv[2]))
			ft_exit("Wrong input, not a port");
		port = atoi(argv[2]);
		std::cout << "after port = " << port << std::endl;
		if (port <= 0 || port > 65535)
			ft_exit("Port number must be between 0 and 65335");
		if (check_port(argv[1]))
			ft_exit("Wrong input, not a Hostname");

		// set argument 
		bot.setPort(port);
		bot.setHostname(atoi(argv[2]));
		bot.setChannel(argv[3]);
		bot.setNick(argv[4]);

		// bot connect to serv
		bot.connect_to_serv();

		while (1)
		{
			
		}
		
	}
	else
	{
		std::cerr << "ERROR ARGS, Usage: ./bot hostname port channel nick" << std::endl;
		return (1);
	}
	return (0);
}