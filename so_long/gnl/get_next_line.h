/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:47:35 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/18 21:15:45 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define END 0
# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

int		gnl_ft_strlcpy(char *dest, const char *src, size_t d_size);
char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_strdup(const char *s);
size_t	gnl_ft_strlen(const char *str);
int		gnl_ft_strchr(const char *str, int c);
#endif