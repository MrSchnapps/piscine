# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/18 19:59:12 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = srcs/bsq.c srcs/bsq_resolv_char.c srcs/bsq_resolv_short.c srcs/file.c srcs/main.c srcs/stdin.c srcs/str.c srcs/utils.c
OBJ = srcs/bsq.o srcs/bsq_resolv_char.o srcs/bsq_resolv_short.o srcs/file.o srcs/main.o srcs/stdin.o srcs/str.o srcs/utils.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs/
INCDIR = ./includes/

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(SRCDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
