# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 13:01:02 by ddecourt          #+#    #+#              #
#    Updated: 2022/12/05 13:57:05 by ddecourt         ###   ########.fr        #
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

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98

SRCS =	server/main.cpp \
		server/server.cpp \
		server/channel/channel.cpp \
		server/user/user.cpp \
		server/reply.cpp \


CC	=	c++
RM	=	rm -f

MESSAGE = Compilation ok - ready to test

INCLUDES = -I./server/

OBJS		:=	$(SRCS:.cpp=.o)

.PHONY		:	all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(NAME)
	@echo "${GREEN}\nCompilation OK - ready to test\n${RESET}"

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all