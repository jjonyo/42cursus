# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 21:34:57 by jonghpar          #+#    #+#              #
#    Updated: 2022/03/23 03:01:50 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
SRCS 	= main.c init.c operations_pr.c operations_rr.c operations_s.c parse.c push_swap.c sort_utils.c sort.c stack.c utils.c
SRCS_F 	= srcs/
OBJS 	= ${SRCS:.c=.o}

INCLUDE_DIRS = includes
LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g
DBGFLAGS = -g -fsanitize=address


all:		$(NAME)

$(NAME):
					$(CC) $(CFLAGS) -I$(INCLUDE_DIRS) -c $(addprefix $(SRCS_F), $(SRCS))
					make -C $(LIBF_DIR)
					$(CC) $(FLAGS) $(LIBFT) -I$(INCLUDE_DIRS) $(OBJS) -o $(NAME)
clean:
					make clean -C $(LIBF_DIR)
					rm -f ${OBJS}

fclean: 	clean
					make -C $(LIBF_DIR) fclean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re