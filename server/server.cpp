/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 15:39:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server()
{
    std::cout << "Create new server" << std::endl;
}

Server::~Server()
{
    std::cout << "Server deleted" << std::endl;
}


//https://www.geeksforgeeks.org/socket-programming-cc/
void Server::init()
{
    int opt = 1;
    int PORT = 8000;
    int sockfd = -1;

    if ((sockfd = (socket(AF_INET, SOCK_STREAM, 0))) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    else
        std::cout << "Socket succesfully created" << std::endl;

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0)
    {
        perror("fcntl failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);  //The htons() function converts the unsigned short integer hostshort from host byte order to network byte order.

    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, address.sin_port) < 0) 
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}