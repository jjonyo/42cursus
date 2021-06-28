# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 12:57:20 by jonghpar          #+#    #+#              #
#    Updated: 2021/06/28 17:01:03 by jonghpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a
SRCS					= ft_memset.c \
						 ft_bzero.c \
						 ft_memcpy.c \
						 ft_memccpy.c \
						 ft_memmove.c \
						 ft_memchr.c \
						 ft_memcmp.c \
						 ft_strlen.c \
						 ft_strlcpy.c \
						 ft_strlcat.c \
						 ft_strchr.c \
						 ft_strrchr.c \
						 ft_strncmp.c \
						 ft_strnstr.c \
						 ft_atoi.c \
						 ft_isalpha.c \
						 ft_isdigit.c \
						 ft_isalnum.c \
						 ft_isascii.c \
						 ft_isprint.c \
						 ft_toupper.c \
						 ft_tolower.c \
						 ft_calloc.c \
						 ft_strdup.c \
						 ft_substr.c \
						 ft_strjoin.c \
						 ft_strtrim.c \
						 ft_split.c \
						 ft_itoa.c \
						 ft_strmapi.c \
						 ft_putchar_fd.c \
						 ft_putstr_fd.c \
						 ft_putendl_fd.c \
						 ft_putnbr_fd.c

B_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJS					= $(SRCS:%.c=%.o)
B_OBJS				= $(B_SRCS:%.c=%.o)
FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			gcc $(FLAGS) -c $(SRCS) -I./
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		gcc $(FLAGS) -c $(B_SRCS) -I./
		ar rc $(NAME) $(OBJS) $(B_OBJS)

clean	:
		rm -f $(OBJS) $(B_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean bonus fclean re