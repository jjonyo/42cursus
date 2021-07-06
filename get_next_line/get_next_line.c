/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/06 01:51:57 by jonghpar         ###   ########.fr       */
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

int	gnl_exit(char **buf, int flag)
{
	free(*buf);
	*buf = NULL;
	return (flag);
}

//마지막 줄이면 그 마지막 offset까지하여 line에 넘기고 END로 리턴
//마지막 줄이 아니면 개행까지의 offset계산하여 line에 넘기고 SUCCESS로 리턴
int	get_line(char **mem, char **line, char **buf)
{
	char	*tmp;
	int		offset;

	offset = ft_strchr(*mem, '\n');
	*line = (char *)malloc(offset + 1);
	if (!line || ft_strlcpy(*line, *mem, offset + 1) == -1)
	{
		free(*line);
		*line = NULL;
		return (gnl_exit(buf, ERROR));
	}
	tmp = *mem;
	*mem = ft_strdup(*mem + offset + 1);
	free(tmp);
	return (gnl_exit(buf, SUCCESS));
}

int	get_eof_line(char **mem, char **line, char **buf)
{
	int	offset;

	if (!*mem)
	{
		*line = ft_strdup("");
		return (gnl_exit(buf, END));
	}
	if (ft_strchr(*mem, '\n') != -1)
		return (get_line(mem, line, buf));
	offset = 0;
	while ((*mem)[offset])
		offset++;
	*line = (char *)malloc(offset + 1);
	if (!line || ft_strlcpy(*line, *mem, offset + 1) == -1)
	{
		free(*line);
		free(*mem);
		*line = NULL;
		*mem = NULL;
		return (gnl_exit(buf, ERROR));
	}
	free(*mem);
	*mem = NULL;
	return (gnl_exit(buf, END));
}

int	get_next_line(int fd, char **line)
{
	int			offset;
	char		*buf;
	static char	*mem[OPEN_MAX + 1];

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf || fd < 0 || !line || OPEN_MAX < fd || BUFFER_SIZE < 1)
		return (gnl_exit(&buf, ERROR));
	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset <= 0)
			break ;
		buf[offset] = '\0';
		if (!save_buf(&mem[fd], buf))
			return (gnl_exit(&buf, ERROR));
		if (ft_strchr(mem[fd], '\n') != -1)
			return (get_line(&mem[fd], line, &buf));
	}
	if (offset < 0)
		return (gnl_exit(&buf, ERROR));
	return (get_eof_line(&mem[fd], line, &buf));
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	int fd;
// 	int ret;
// 	char *line;

// 	fd = open("empty_lines", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while (get_next_line(180, &line))
// 	{
// 		printf("%s\n",line);
// 		free(line);
// 	}
// 	printf("%s\n",line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }