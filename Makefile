# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parallels <parallels@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 13:01:02 by ddecourt          #+#    #+#              #
#    Updated: 2023/01/09 22:23:04 by parallels        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN        := ""
	RESET        := ""
endif


NAME =	ircserv
BONUS	= bot

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -std=c++98

SRCS =	server/main.cpp \
		server/server.cpp \
		server/channel/channel.cpp \
		server/user/user.cpp \
		server/reply/reply.cpp \
		server/reply/error.cpp \
		server/command/pass.cpp \
		server/command/nick.cpp \
		server/command/user.cpp \
		server/command/mode.cpp \
		server/command/ping.cpp \
		server/command/pong.cpp \
		server/command/join.cpp \
		server/command/quit.cpp \
		server/command/whois.cpp \
		server/command/privmsg.cpp \
		server/command/list.cpp \
		server/command/part.cpp \
		server/command/notice.cpp \
		server/command/operator_cmds/invite.cpp \
		server/command/operator_cmds/kick.cpp \
		server/command/operator_cmds/topic.cpp \
		server/command/command.cpp \
		server/message/message.cpp \

SRCS_B	= bonus/bot_connect.cpp \
				bonus/bot.cpp \

CC	=	c++
RM	=	rm -f

MESSAGE = Compilation ok - ready to test

INCLUDES = -I./server/
INCLUDES_B = -I./bonus/

OBJS		:=	$(SRCS:.cpp=.o)
OBJS_B		:=	$(SRCS_B:.cpp=.o)

.PHONY		:	all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(NAME)
	@echo "${GREEN}\nCompilation OK - ready to test\n${RESET}"

bonus: $(BONUS)

$(BONUS)	: $(OBJS_B)
	$(CC) $(CFLAGS) $(INCLUDES_B) $^ -o $(BONUS)
	@echo "${GREEN}\nCompilation OK - ready to test\n${RESET}"

fclean		: clean
	$(RM) $(NAME) $(BONUS)

clean		:
	$(RM) $(OBJS) $(OBJS_B)

re			:	fclean all