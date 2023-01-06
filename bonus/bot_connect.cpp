/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_connect.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:49:08 by parallels         #+#    #+#             */
/*   Updated: 2023/01/04 12:03:22 by parallels        ###   ########.fr       */
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
		if (!check_port(argv[2]))
			ft_exit("Wrong input, not a port");
		port = atoi(argv[2]);
		if (port <= 0 || port > 65535)
			ft_exit("Port number must be between 0 and 65335");

		// init the variable
		bot.init(port, argv[1], argv[3], argv[4]);

		// set socket and bot connect to serv
		bot.connect_to_serv();

		bot.run();
		
	}
	else
	{
		std::cerr << "ERROR ARGS, Usage: ./bot hostname port channel nick" << std::endl;
		return (1);
	}
	return (0);
}