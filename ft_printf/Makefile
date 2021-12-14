# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:04:32 by jonghpar          #+#    #+#              #
#    Updated: 2021/12/20 21:13:16 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

CC = gcc -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_printf_utils.c

OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	${CC} -c ${SRCS} -I./${HEADER}
	ar -rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all