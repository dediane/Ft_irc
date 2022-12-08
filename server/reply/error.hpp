/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:15:54 by ddecourt          #+#    #+#             */
/*   Updated: 2022/12/08 18:45:21 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

std::string ERR_NOSUCHNICK(std::string nickname);
std::string ERR_NOSUCHSERVER(std::string server);
std::string ERR_NOSUCHCHANNEL(std::string channel);
std::string ERR_CANNOTSENDTOCHAN(std::string channel);
std::string ERR_TOOMANYCHANNELS(std::string channel);
std::string ERR_TOOMANYTARGETS(std::string target);
std::string ERR_NOORIGIN();
std::string ERR_NORECIPIENT();
std::string ERR_NOTEXTTOSEND();
std::string ERR_NOTOPLEVEL(std::string mask);
std::string ERR_UNKNOWNCOMMAND(std::string command);
std::string ERR_NONICKNAMEGIVEN(std::string nickname);
std::string ERR_ERRONEUSNICKNAME(std::string nickname);
std::string ERR_NICKNAMEINUSE(std::string nickname);
std::string ERR_USERNOTINCHANNEL(std::string nickname, std::string channel);
std::string ERR_NOTONCHANNEL(std::string channel);
std::string ERR_USERONCHANNEL(std::string user, std::string channel);
std::string ERR_NOLOGIN(std::string user);
std::string ERR_SUMMONDISABLED();
std::string ERR_NOTREGISTERED();
std::string ERR_NEEDMOREPARAMS(std::string command);
std::string ERR_ALREADYREGISTRED();
std::string ERR_NOPERMFORHOST();
std::string ERR_PASSWDMISMATCH();
std::string ERR_YOUREBANNEDCREEP();