# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/19 09:12:24 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS = srcs/ft_display_file.c
OBJ = srcs/ft_display_file.o
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
