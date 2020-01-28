# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/18 23:47:04 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = srcs/main.c srcs/ft_putstr.c srcs/ft_putchar.c
OBJ = srcs/ft_putstr.o srcs/main.o srcs/ft_putchar.o
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
