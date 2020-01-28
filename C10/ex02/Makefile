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

NAME = ft_tail
SRCS = srcs/ft_putchar.c srcs/main.c srcs/ft_putstr.c srcs/ft_str_is_numeric.c srcs/ft_atoi.c srcs/ft_stdin.c srcs/ft_utils.c
OBJ = srcs/ft_putstr.o srcs/main.o srcs/ft_putchar.o srcs/ft_str_is_numeric.o srcs/ft_atoi.o srcs/ft_stdin.o srcs/ft_utils.o
#SRCS = $(willcard srcs/*.c)
#OBJ = (SRCS:.c=.o)
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
