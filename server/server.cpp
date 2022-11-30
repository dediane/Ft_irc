/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 22:44:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server()
{
    last_ping = time(0);
    heartbeat = time(0);
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
    int PORT = 1050;

    if (( sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
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

    //memset(&this->fds[0], 0 , sizeof(fds));
    fds.push_back(pollfd()); //if we don't push_back an element to "malloc" the space for a pollfd struct -> segv
    fds.back().fd = sockfd;
    fds.back().events = POLLIN;
}

void Server::execute()
{
    //https://www.ibm.com/docs/en/i/7.2?topic=designs-using-poll-instead-select
    
    int ping = 5000;
    // int timeout = (3 * 60 * 1000);
    
    std::cout << "Start executing" << std::endl;
    //int poll(struct pollfd *fds, nfds_t nfds, int timeout);
    // fds -> Use ref ptr &myvar[0]
    // nfds -> Nbr of fd open myvar.size()
    // timeout -> heartbeat timeout ping delay from, config (1 min)
    
    int rc = -1;
    //if ( poll(&fds[0], fds.size(), ping) < 0)
    if ((rc = poll(&this->fds[0], fds.size(), ping)) < 0)
    {
        std::cerr << "  poll() failed." << std::endl;
        // exit(EXIT_FAILURE);
        return;
    }
    std::cout << " SOCKFD = "<< sockfd << std::endl;
    
    // if (rc == 0)
    // {
    //     std::cerr << "  poll() timed out.  End program." << std::endl;
    //     return;
    //     // exit(EXIT_FAILURE);
    // }
    if(this->fds[0].revents == POLLIN)
        accept_new_user();
    else
    {
        //iterer sur les fd 
        //for
            //if(this->fds[it].revents == POLLIN)
            //    receive (UDF)
        std::cout << "need to find back the users of POLLIN" << std::endl;
    }
}

void Server::accept_new_user()
{
    std::cout << "need to accept a user in the channel" << std::endl;
    sockaddr_in address;
    socklen_t len = sizeof(address);

    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    int fd = accept(sockfd, (struct sockaddr*)&address, &len);
    if ( fd < 0)
        return;
    // User newuser;
    // (fd, address);
    // users.insert(std::make_pair(fd, newuser));
}