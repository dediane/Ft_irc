/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:47:46 by parallels         #+#    #+#             */
/*   Updated: 2022/12/31 17:09:48 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bot.hpp"

			///////////////////////////////////
			///			Constructor			///
			///////////////////////////////////
Bot::Bot(void)
{
	// Constructor Default
    port = 0;
	hostname = 0;
	channel = "NULL";
	nick = "NULL";
	bot_name = "ShownBot";
}

Bot::Bot(int Port, int Hostname, std::string Channel, std::string Nick) :
	port(Port), hostname(Hostname), channel(Channel), nick(Nick) 
{
	// Constructor Params
	bot_name = "ShownBot";
}

Bot::Bot(Bot &rhs)
{
	// Constructor Copy
	*this = rhs;
}

Bot::~Bot()
{
	// Destructor
}

Bot	&Bot::operator=(Bot &rhs)
{
	port = rhs.getPort();
	hostname = rhs.getHostname();
	channel = rhs.getChannel();
	nick = rhs.getNick();
	return (*this);
}

			///////////////////////////////////
			///			Fonction			///
			///////////////////////////////////

void	Bot::init(void)
{
	/* Début de la création du socket */
	if (( sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    //The htons() function converts the unsigned short integer 
    //hostshort from host byte order to network byte order.
	
	/* Fin de la création du socket */
	
}

void	Bot::connect_to_serv(void)
{
	if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0)
		ft_exit("Do not connect to the server");
	std::cout << "Nick bot " << bot_name << std::endl;
	send (sockfd, bot_name.c_str(), bot_name.length(), 0);
	
	std::cout << "Nick user " << nick << std::endl;
	send (sockfd, nick.c_str(), nick.length(), 0);
	
	std::cout << "JOIN " << channel << std::endl;
	send (sockfd, channel.c_str(), channel.length(), 0);
	
	std::cout << "PRIVMSG " << channel << " :yop :-)" << std::endl;
	send (sockfd, channel.c_str(), channel.length(), 0);
}

			///////////////////////////////////
			///			Setter				///
			///////////////////////////////////
void	Bot::setPort(int Port)
{
	port = Port;
}

void	Bot::setHostname(int Hostname)
{
	hostname = Hostname;
}

void	Bot::setChannel(std::string Channel)
{
	channel = Channel;
}

void	Bot::setNick(std::string Nick)
{
	nick = Nick;
}

			///////////////////////////////////
			///			Getter				///
			///////////////////////////////////
int		Bot::getPort(void)
{
	return (port);
}

int		Bot::getHostname(void)
{
	return (hostname);
}

std::string	Bot::getChannel(void)
{
	return (channel);
}

std::string	Bot::getNick(void)
{
	return (nick);
}

void    ft_exit(std::string str)
{
	std::cerr << str << std::endl;
	exit(1);
}