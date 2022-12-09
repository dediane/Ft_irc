/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:05:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/09 16:32:34 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Server::Server()
{
    last_ping = time(0);
    heartbeat = time(0);
    creation = time(0);
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
    address.sin_port = htons(PORT);
    //The htons() function converts the unsigned short integer 
    //hostshort from host byte order to network byte order.

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
    //SEGV if we don't push_back an element to "malloc" the space for a pollfd 
    fds.push_back(pollfd());
    fds.back().fd = sockfd;
    fds.back().events = POLLIN;
}

void Server::execute()
{
    //https://www.ibm.com/docs/en/i/7.2?topic=designs-using-poll-instead-select
    
    int ping = 5000;
    // int timeout = (3 * 60 * 1000);
    
    //std::cout << "Start executing" << std::endl;
    
    // fds -> Use ref ptr &myvar[0]
    // nfds -> Nbr of fd open myvar.size()
    // timeout -> heartbeat timeout ping delay
    
    //int poll(struct pollfd *fds, nfds_t nfds, int timeout);
    int rc = -1;
    if ((rc = poll(&this->fds[0], fds.size(), ping)) < 0)
    {
        std::cerr << "  poll() failed." << std::endl;
        return;
    }
    
    // if (rc == 0)
    // {
    //     std::cerr << "  poll() timed out.  End program." << std::endl;
    //     return;
    // }
    
    if(this->fds[0].revents == POLLIN)
        accept_new_user();
    else
    {
        //How do I access each element?  
        //iterer sur les fd 
        //for
            //if(this->fds[it].revents == POLLIN)
            //    receive (UDF)
        std::vector<pollfd>::iterator it; 
         for (it = fds.begin() ; it != fds.end(); it++)
        {
            if((*it).revents == POLLIN)
            {
                User user = get_user_by_fd((*it).fd);
                Message message(&user, this);
                message.receive_msg();
                //user.receive();
            }
        }
        //std::cout << "need to find back the users of POLLIN" << std::endl;
    }
}

void Server::accept_new_user()
{
    //std::cout << "need to accept a user in the channel" << std::endl;
    sockaddr_in address;
    socklen_t len = sizeof(address);
    //std::string infos;

    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    int fd = accept(sockfd, (struct sockaddr*)&address, &len);
    if ( fd < 0)
        return;
    User newuser(fd, address);
    std::map<int, User>::iterator it;
    it = users.begin();
    users.insert(it, std::make_pair(fd, newuser));
    
    fds.push_back(pollfd());
    fds.back().fd = fd;
    fds.back().events = POLLIN;
}

std::vector<std::string> Server::get_all_nicknames()
{
    std::vector<std::string> ret;
    std::map<int, User>::iterator it;
    for (it = users.begin(); it != users.end(); it++)
        ret.push_back((*it).second.getNickname());
    return ret;
}

// void Server::do_handshake(int fd, User user)
// {
//     if (user.isRegistered())
//     {
//         std::string buffer = RPL_WELCOME(user);
//         if (send(fd, buffer.c_str(), buffer.length(), 0) == -1)
//             std::cout << "error" << std::endl;

//         buffer = RPL_YOURHOST(user);
//         if (send(fd, buffer.c_str(), buffer.length(), 0) == -1)
//             std::cout << "error" << std::endl;
            
//         buffer = RPL_CREATED(user, this->getCreationTime());
//         if (send(fd, buffer.c_str(), buffer.length(), 0) == -1)
//             std::cout << "error" << std::endl;
//     }
// }

User Server::get_user_by_fd(int user_fd)
{
    std::map<int, User>::iterator it;
    for (it = users.begin(); it != users.end(); it++)
    {
        if((*it).first == user_fd) 
        {    
            break;
        }
    }
    return ((*it).second);
}