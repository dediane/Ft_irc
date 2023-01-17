/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:31 by ddecourt          #+#    #+#             */
/*   Updated: 2023/01/17 13:18:46 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Message::Message()
{
    
}

Message::Message(User *user, Server *server)
{
    _user = user;
    _server = server;
}

Message::Message(Message &lhs)
{
    (void)lhs;
}

Message::~Message()
{ 
}

Server  *Message::getserver() { return _server; }
User    *Message::getuser() { return _user; }



void Message::make_uppercase(std::string &token)
{
//	std::cout << "making command uppercase " << std::endl;
	for(size_t i = 0; i < token.length(); i++)
		token[i] = std::toupper(token[i]);
}

void Message::print_tokens(std::vector<std::string>  tokens)
{
	if (tokens.empty())
	{
		std::cout << "cannot print, empty tokens \n";
		return ;
	}
	for(size_t i = 0; i < tokens.size(); i++)
		std::cout <<"\""<< tokens[i]<< "\""<< std::endl;
}

void Message::replacerbyn(std::string &input)
{
	for(size_t i = 0; i < input.size() ; i++){
		if(input[i] == '\r')
			input[i] = '\n';
	}
}

std::vector<std::string> Message::get_split(std::string input, std::string separater) {

	std::vector<std::string> tokens;
	size_t prev = 0;
	size_t current = input.find(separater, prev);

	while (current != std::string::npos){
		if(current - prev > 0)
			tokens.push_back(input.substr(prev, current - prev));
		prev = current + 1;
		while(input[prev] == separater[0])
			prev++;
		current = input.find(separater, prev);
	}
	if(prev < input.length())
		tokens.push_back(input.substr(prev, input.length()));
    return tokens;
}

void Message::split_buffer(std::string recvline)
{
	replacerbyn(recvline);
	std::vector<std::string> cmds = get_split(recvline, "\n");
    std::vector<std::string>::iterator it;
    for (it = cmds.begin(); it != cmds.end(); ++it)
        _messages.push_back(*it);
	// print_tokens(cmds);
}

std::vector<std::string> Message::getTokens(std::string cmd)
{
    std::vector<std::string> tokens = get_split(cmd, " ");
	make_uppercase(tokens[0]);
	// print_tokens(tokens);
	return (tokens);
}

int Message::receive_msg()
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t response_size = recv(_user->getFd(), buffer, BUFFER_SIZE, 0);
    if (response_size == -1)
        return (-1);
    if (response_size == 0)
        return (-1);
    buffer[response_size] = '\0';
    _user->msgbuffer += buffer;
    while ( (_user->msgbuffer).find("\n") != std::string::npos)
    {
        if (_user->msgbuffer == "\r\n")
        {
            _user->msgbuffer.clear();
            return -1;
        }
        split_buffer(_user->msgbuffer);
        std::vector<std::string>::iterator it;
        for (it = _messages.begin(); it != _messages.end(); ++it)
            parse_commands(*it);
        _user->msgbuffer.clear();
    }
    return (0);
}

void Message::parse_commands(std::string str)
{
    int index = 0;
    std::vector<std::string> commands = getTokens(str);
    std::vector<std::string>::iterator it;
    for (it = commands.begin(); it != commands.end(); ++it)
    {
        //std::cout << "Command message -> " << (*it) << std::endl;
        if (it == commands.begin())
        {
            index = 0;
            std::vector<std::string>::iterator it2;
            for (it2 = _user->_cmd->_commandlist.begin(); it2 != _user->_cmd->_commandlist.end(); ++it2)
            {
                if (*it == *it2)
                {
                    //std::cout << index << std::endl;
                    //std::cout << "command = " << *it2 << std::endl;
                    _user->_cmd->execute(*it, this, commands, index);
                    // if (_user->isRegistered())
                    // {
                        // std::cout << "[message.cpp] Nickname = " << _user->getNickname() << std::endl;
                        // std::cout << "[message.cpp] Username = " << _user->getUsername() << std::endl;
                        // std::cout << "[message.cpp] Realname = " << _user->getRealname() << std::endl;
                        // std::cout << "[message.cpp] Hostname = " << _user->getHostname() << std::endl;
                        
                    // }
                }
                index++;
            }
        }
    }
}


void Message::do_handshake()
{
    User *usr = getuser();
    Server *server = getserver();
    (void)server;
    send_reply(usr->getFd(), RPL_WELCOME(*usr));
    send_reply(usr->getFd(), RPL_YOURHOST(*usr));
    send_reply(usr->getFd(), RPL_CREATED(*usr, server->getCreationTime()));
}

void Message::setuser(User *user)
{
    _user = user;
}