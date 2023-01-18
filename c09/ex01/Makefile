# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 11:56:54 by jeolim            #+#    #+#              #
#    Updated: 2022/06/07 20:49:32 by jeolim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=${SRCS:.c=.o}
HEADER=includes
NAME=libft.a
RM=rm -f
AR=ar rsc

all: ${NAME}
	
${NAME}: ${OBJS}
	${AR} $@ $^

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all fclean clean re
