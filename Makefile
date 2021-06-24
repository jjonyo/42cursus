# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 12:57:20 by jonghpar          #+#    #+#              #
#    Updated: 2021/06/24 13:18:03 by jonghpar         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

SRCS					= ft_atoi.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_memccpy.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_strchr.c \
					  ft_strlcat.c \
					  ft_strlen.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_strrchr.c \
					  ft_tolower.c \
					  ft_toupper.c

BNS_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			gcc $(FLAGS) -c $(SRCS) -I./
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		gcc $(FLAGS) -c $(BNS_SRCS) -I./
		ar rc $(NAME) $(BNS_OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS)
	gcc -shared -o libft.so $(OBJS)

.PHONY	:	all clean fclean re