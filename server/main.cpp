/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:03:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/30 15:37:45 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include "server.hpp"

void handler(int sig)
{
    std::cout << "OK" << std::endl;
    (void) sig;
    exit(1);
}

bool stop = false;

int main(int argc, char**argv)
{
    (void) argv;
    if (argc != 3)
    {
        std::cerr << "Usage: ./ircserv <port> <server> " << std::endl;
        return 1;
    }
    std::signal(SIGINT, handler);
    std::cout << "OK" << std::endl;

    Server server;
    server.init();

    while (!stop)
        usleep(1);
}