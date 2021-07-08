/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/08 11:17:15 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*gnl_exit(char **buf, char **line, int flag)
{
	free(*buf);
	*buf = NULL;
	if (flag == ERROR || flag == END)
	{
		free(*line);
		*line = NULL;
	}
	return (*line);
}

char	*get_line(char **mem, char **line, char **buf)
{
	char	*tmp;
	int		offset;

	offset = ft_strchr(*mem, '\n');
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *mem, offset + 1) == -1)
		return (gnl_exit(buf, line, ERROR));
	tmp = *mem;
	*mem = ft_strdup(*mem + offset + 1);
	free(tmp);
	return (gnl_exit(buf, line, SUCCESS));
}

char	*get_eof_line(char **mem, char **line, char **buf)
{
	int	offset;

	if (!*mem)
		return (gnl_exit(buf, line, END));
	if (ft_strchr(*mem, '\n') != -1)
		return (get_line(mem, line, buf));
	offset = ft_strchr(*mem, '\0');
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *mem, offset + 1) == -1)
	{
		free(*mem);
		*mem = NULL;
		return (gnl_exit(buf, line, ERROR));
	}
	free(*mem);
	*mem = NULL;
	return (gnl_exit(buf, line, SUCCESS));
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
		return (gnl_exit(&buf, &line, ERROR));
	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset <= 0)
			break ;
		buf[offset] = '\0';
		if (!save_buf(&mem[fd], buf))
			return (gnl_exit(&buf, &line, ERROR));
		if (ft_strchr(mem[fd], '\n') != -1)
			return (get_line(&mem[fd], &line, &buf));
	}
	if (offset < 0)
		return (gnl_exit(&buf, &line, ERROR));
	return (get_eof_line(&mem[fd], &line, &buf));
}
