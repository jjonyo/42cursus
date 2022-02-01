# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 12:15:25 by jonghpar          #+#    #+#              #
#    Updated: 2022/02/01 21:44:42 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
SRCS 	= pipex.c utils.c
SRCS_F 	= srcs/
OBJS 	= ${SRCS:.c=.o}

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g
DBGFLAGS = -g -fsanitize=address


all:		$(NAME)

$(NAME):
					$(CC) $(CFLAGS) -c $(addprefix $(SRCS_F), $(SRCS))
					make -C $(LIBF_DIR)
					$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)
clean:
					make clean -C $(LIBF_DIR)
					rm -f ${OBJS}

fclean: 	clean
					make -C $(LIBF_DIR) fclean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re