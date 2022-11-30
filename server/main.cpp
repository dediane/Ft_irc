/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:03:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 22:02:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include "server.hpp"

#define PASSWORD "123pass"
bool stop = false;

void handler(int sig)
{
    std::cout << "OK" << std::endl;
    (void) sig;
    exit(1);
}

bool check_port(std::string port)
{
    for (unsigned long i = 0; i < port.size(); i++)
    {
        if (port[i] < '0' || port[i] > '9')
            return false;
    }
    return true;
}

bool check_password(std::string password)
{
    if(PASSWORD != password)
        return false;
    return true;
}

int main(int argc, char**argv)
{
    (void) argv;
    if (argc != 3)
    {
        std::cerr << "Usage: ./ircserv <port> <server> " << std::endl;
        return 1;
    }
    
    if (check_port(argv[1]) == false)
    {
        std::cerr << "Wrong input, not a port" << std::endl;
        exit(1);
    }

    if (check_password(argv[2]) == false)
    {
        std::cerr << "Wrong Password" << std::endl;
        exit(1);
    }
    
    std::signal(SIGINT, handler);
    std::cout << "OK" << std::endl;

    Server server;
    server.init();

    while (!stop)
        server.execute();
}

