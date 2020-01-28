# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/21 14:31:46 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = srcs/dico.c srcs/file.c srcs/utils.c srcs/line.c srcs/main.c srcs/dico_utils.c
OBJ = srcs/dico.o srcs/file.o srcs/utils.o srcs/line.o srcs/main.o srcs/dico_utils.o
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
