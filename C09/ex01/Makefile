# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 04:32:10 by judecuyp          #+#    #+#              #
#    Updated: 2019/07/15 00:25:33 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

POINT = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			
			ar rc ${NAME} ${POINT}

all:		${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all
