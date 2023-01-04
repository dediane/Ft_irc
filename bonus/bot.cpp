/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:47:46 by parallels         #+#    #+#             */
/*   Updated: 2023/01/04 11:58:27 by parallels        ###   ########.fr       */
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
	hostname = "NULL";
	channel = "NULL";
	nick = "NULL";
	bot_name = "ShownBot";
}

Bot::Bot(int Port, std::string Hostname, std::string Channel, std::string Nick) :
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

void	Bot::init(int port, char *hostname, char *channel, char *nick)
{
	// set argument 
	setPort(port);
	setHostname(hostname);
	setChannel(channel);
	setNick(nick);

	std::cout << "The bot have for agrs:" << std::endl;
	std::cout << "Port: " << this->port << std::endl;
	std::cout << "Hostname: " << this->hostname << std::endl;
	std::cout << "Channel: " << this->channel << std::endl;
	std::cout << "Nick: " << this->nick << std::endl << std::endl;;
}

void	Bot::connect_to_serv(void)
{
	struct sockaddr_in address;
	struct hostent *host;
	/* Début de la création du socket */
	if (( sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	if (!(host = gethostbyname(hostname.c_str())))
		ft_exit("Error gethostbyname failed");
	address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *((struct in_addr*)host->h_addr);
	//The htons() function converts the unsigned short integer 
    //hostshort from host byte order to network byte order.
	/* Fin de la création du socket */

	if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1)
		ft_exit("Do not connect to the server");
	std::cout << "Bot Name: " << bot_name << std::endl;
	send (sockfd, bot_name.c_str(), bot_name.length(), 0);
	
	std::cout << "User Nick: " << nick << std::endl;
	send (sockfd, nick.c_str(), nick.length(), 0);
	
	std::cout << "Join Channel: " << channel << std::endl;
	send (sockfd, channel.c_str(), channel.length(), 0);
	
	std::cout << "Privmsg " << channel << " :yop :-)" << std::endl;
	send (sockfd, channel.c_str(), channel.length(), 0);
}

			///////////////////////////////////
			///			Setter				///
			///////////////////////////////////
void	Bot::setPort(int Port)
{
	port = Port;
}

void	Bot::setHostname(std::string Hostname)
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

std::string		Bot::getHostname(void)
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