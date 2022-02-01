# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 12:15:25 by jonghpar          #+#    #+#              #
#    Updated: 2022/02/01 16:31:13 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
PROG	= pipex

SRCS 	= pipex.c
SRCS_F 	= srcs/
OBJS 	= ${SRCS:.c=.o}
OBJS_F	= _objFiles/
MAIN	= srcs/pipex.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

HEADER	= -I./includes/

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g
DBGFLAGS = -g -fsanitize=address


all:		$(NAME)

$(NAME):
					@mkdir -p $(OBJS_F)
					@$(CC) $(CFLAGS) -c $(addprefix $(SRCS_F), $(SRCS))
					@mv $(OBJS) $(OBJS_F)
					@make -C $(LIBF_DIR)
					@$(CC) $(FLAGS) $(LIBFT) $(addprefix $(OBJS_F), $(OBJS)) -o $(NAME)
test:
					@mkdir -p $(OBJS_F)
					@$(CC) $(DBGFLAGS) -c $(addprefix $(SRCS_F), $(SRCS))
					@mv $(OBJS) $(OBJS_F)
					@make -C $(LIBF_DIR)
					@$(CC) $(DBGFLAGS) $(LIBFT) $(addprefix $(OBJS_F), $(OBJS)) -o $(NAME)
					
clean:
					@make clean -C ./libft
					@rm -rf $(OBJS_F)
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make -C $(LIBF_DIR) fclean
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re bonus