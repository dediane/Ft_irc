/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:26 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/27 13:02:10 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

//401
std::string ERR_NOSUCHNICK(std::string nickname) {return(nickname + " :No such nick/channel\r\n");}
//402
std::string ERR_NOSUCHSERVER(std::string server) {return(server + " :No such server\r\n");}
//403
std::string ERR_NOSUCHCHANNEL(std::string channel) {return(channel + " :No such channel\r\n");}
//404
std::string ERR_CANNOTSENDTOCHAN(std::string channel) {return(channel + " :Cannot send to channel\r\n");}
//405
std::string ERR_TOOMANYCHANNELS(std::string channel) {return(channel + " :You have joined too many channels\r\n");}
//406
std::string ERR_WASNOSUCHNICK(std::string nickname) {return(nickname + " :There was no such nickname\r\n");}
//407
std::string ERR_TOOMANYTARGETS(std::string target) {return(target + " :Duplicate recipients. No message delivered\r\n");}
//409
std::string ERR_NOORIGIN() {return (" :No origin specified\r\n");}
//411
std::string ERR_NORECIPIENT() {return(" :No recipient given\r\n");}
//412
std::string ERR_NOTEXTTOSEND() {return(" :No text to send\r\n");}
//413
std::string ERR_NOTOPLEVEL(std::string mask) {return(mask + " :No toplevel domain specified\r\n");}
//414
//421
std::string ERR_UNKNOWNCOMMAND(std::string command) {return(command + " :Unknown command\r\n");}
//422
//423
//424
//431
std::string ERR_NONICKNAMEGIVEN(std::string nickname) {return(nickname + " :No nickname given\r\n");}
//432
std::string ERR_ERRONEUSNICKNAME(std::string nickname) {return(nickname + " :Erroneus nickname\r\n");}
//433
std::string ERR_NICKNAMEINUSE(std::string nickname) {return(nickname + " :Nickname is already in use\r\n");}
//436
//441
std::string ERR_USERNOTINCHANNEL(std::string nickname, std::string channel) {return(nickname + channel + " :is already on channel\r\n");}
//442
std::string ERR_NOTONCHANNEL(std::string channel) {return(channel + " :You're not on that channel\r\n");}
//443
std::string ERR_USERONCHANNEL(std::string user, std::string channel) {return(user + channel + " :is already on channel\r\n");}
//444
std::string ERR_NOLOGIN(std::string user) {return(user + " :User not logged in\r\n");}
//445
std::string ERR_SUMMONDISABLED() {return(" :SUMMON has been disabled\r\n");}
//446

//451
std::string ERR_NOTREGISTERED(){return(" :You have not registered\r\n");}
//461
std::string ERR_NEEDMOREPARAMS(std::string command) {return(command + " :Not enough parameters\r\n");}

//462
std::string ERR_ALREADYREGISTRED() {return(" :You may not reregister\r\n");}

//463
std::string ERR_NOPERMFORHOST() {return(" :Your host isn't among the privileged\r\n");}
//464
std::string ERR_PASSWDMISMATCH() {return(" :Password incorrect\r\n");}
//465
std::string ERR_YOUREBANNEDCREEP() {return(" :You are banned from this server\r\n");}
//467
//471
//472
std::string ERR_UNKNOWNMODE(char c) {return(c + " :is unknown mode char to me\r\n");}
//473
std::string ERR_INVITEONLYCHAN(std::string channel) {return(channel + " :Cannot join channel (+i)\r\n");}
//474
//475
std::string ERR_BADCHANNELKEY(std::string channel) {return(channel + " :Cannot join channel (+k)\r\n");}
//481
//482
std::string ERR_CHANOPRIVNEEDED(std::string channel) {return(channel + " :You're not channel operator\r\n");}
//483
//491
//501
//502
std::string ERR_USERSDONTMATCH() {return(" :Cant change mode for other users\r\n");}
