/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:47:35 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/05 13:14:45 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define END 0
# define ERROR -1
# define TRUE 1
# define FALSE 0

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 65
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dest, const char *src, size_t d_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
#endif