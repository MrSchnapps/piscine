# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/17 16:26:06 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = srcs/ft_putchar.c srcs/ft_putnbr.c srcs/main.c srcs/ft_strlen.c srcs/ft_operations.c
OBJ = srcs/ft_putchar.o srcs/ft_putnbr.o srcs/main.o srcs/ft_strlen.o srcs/ft_operations.o
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
