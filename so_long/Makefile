# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:24:07 by jonghpar          #+#    #+#              #
#    Updated: 2022/04/19 02:49:36 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
SRCS 	= so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c utils.c init.c move.c image.c
SRCS_F 	= srcs/
OBJS 	= ${SRCS:%.c=%.o}

INCLUDE_DIRS = includes

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

MLX_DIR = ./mlx
MLX_A = $(MLX_DIR)/libmlx.a

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g
DBGFLAGS = -g -fsanitize=address


all:		$(NAME)

$(NAME):	$(OBJS)
					make all -C $(LIBF_DIR)
					make all -C $(MLX_DIR)
					gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o:		%.c
					gcc $(FLAGS) -c $^ -I./ -o $@

clean:
					make clean -C $(LIBF_DIR)
					make clean -C $(MLX_DIR)
					rm -f ${OBJS}

fclean: 	clean
					rm -f $(NAME)
					rm -f $(MLX_A)
					rm -f $(LIBFT)
					make -C $(LIBF_DIR) fclean
					

re:			fclean all

.PHONY: all clean fclean re