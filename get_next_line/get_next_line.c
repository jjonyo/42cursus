/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/22 23:12:06 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buf(char **mem, char *buf)
{
	char	*tmp;

	if (*mem)
	{
		tmp = *mem;
		*mem = ft_strjoin(*mem, buf);
		free(tmp);
	}
	else
		*mem = ft_strdup(buf);
	return (*mem);
}

char	*gnl_exit(char **mem, char **buf, char **line, int flag)
{
	free(*buf);
	*buf = NULL;
	if (flag == ERROR || flag == END)
	{
		free(*mem);
		free(*line);
		*mem = NULL;
		*line = NULL;
	}
	return (*line);
}

char	*get_line(char **mem, char **line, char **buf)
{
	char	*tmp;
	int		offset;

	offset = ft_strchr(*mem, '\n') + 1;
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *mem, offset + 1) == -1)
		return (gnl_exit(mem, buf, line, ERROR));
	tmp = *mem;
	*mem = ft_strdup(*mem + offset);
	free(tmp);
	tmp = NULL;
	return (gnl_exit(mem, buf, line, SUCCESS));
}

char	*get_eof_line(char **mem, char **line, char **buf)
{
	int	offset;

	if (!*mem || !**mem)
		return (gnl_exit(mem, buf, line, END));
	if (ft_strchr(*mem, '\n') != -1)
		return (get_line(mem, line, buf));
	offset = ft_strchr(*mem, '\0');
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *mem, offset + 1) == -1)
		return (gnl_exit(mem, buf, line, ERROR));
	free(*mem);
	*mem = NULL;
	return (gnl_exit(mem, buf, line, SUCCESS));
}

char	*get_next_line(int fd)
{
	int			offset;
	char		*buf;
	char		*line;
	static char	*mem[OPEN_MAX + 1];

	buf = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (!buf || fd < 0 || OPEN_MAX < fd || BUFFER_SIZE < 1)
		return (gnl_exit(&mem[fd], &buf, &line, ERROR));
	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset <= 0)
			break ;
		buf[offset] = '\0';
		if (!save_buf(&mem[fd], buf))
			return (gnl_exit(&mem[fd], &buf, &line, ERROR));
		if (ft_strchr(mem[fd], '\n') != -1)
			return (get_line(&mem[fd], &line, &buf));
	}
	if (offset < 0)
		return (gnl_exit(&mem[fd], &buf, &line, ERROR));
	return (get_eof_line(&mem[fd], &line, &buf));
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("41_no_nl", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("|%s",line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }