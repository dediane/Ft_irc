/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:03:05 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/07 15:39:04 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include "server.hpp"

bool stop = false;

void handler(int sig)
{
    (void) sig;
    std::cout << std::endl << YELLOW << "bye!!" << DEFAULT << std::endl;
    exit(0);
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

void print_title(void)
{
    std::cout <<  \
    "/$$   /$$  /$$$$$$          /$$$$$$   /$$          /$$                        \n" \
    "| $$  | $$ /$$__  $$        /$$__  $$ | $$         |__/                       \n" \
    "| $$  | $$|__/  \\ $$       | $$  \\__//$$$$$$        /$$  /$$$$$$   /$$$$$$$ \n" \
    "| $$$$$$$$  /$$$$$$/       | $$$$   |_  $$_/       | $$ /$$__  $$ /$$_____/   \n" \
    "|_____  $$ /$$____/        | $$_/     | $$         | $$| $$  \\__/| $$        \n" \
    "    | $$| $$             | $$       | $$ /$$     | $$| $$      | $$           \n" \
    "    | $$| $$$$$$$$       | $$       |  $$$$/     | $$| $$      |  $$$$$$$     \n" \
    "    |__/|________//$$$$$$|__/        \\___//$$$$$$|__/|__/       \\_______/   \n" \
    "                |______/                |______/                              \n" << std::endl;
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

    int port = atoi(argv[1]);

    if (port  <= 0 || port > 65535)
     {
        std::cerr << "Port number must be between 0 and 65335" << std::endl;
        exit(1);
    }
    
    std::signal(SIGINT, handler);
    print_title();

    Server server;
    server.setPassword(std::string(argv[2]));
    server.init(port);
    std::cout << GREEN << "==> Server is on !"<< DEFAULT << std::endl;

    while (!stop)
        server.execute();
}

