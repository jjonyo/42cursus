/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/05 01:52:20 by jonghpar         ###   ########.fr       */
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
		tmp = NULL;
	}
	else
	{
		*mem = ft_strdup(buf);
	}
	return (*mem);
}

int	is_new_line(char **mem)
{
	int		i;
	char	*str;

	str = *mem;
	i = 0;
	while (1)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	get_line(char **mem, char **line)
{
	char	*str;
	char	*tmp;
	int		offset;

	str = *mem;
	offset = is_new_line(mem);
	if (offset < 0)
		return (END);
	*line = (char *)malloc(offset + 1);
	if (!line || !ft_strlcpy(*line, str, offset + 1))
	{
		free(*line);
		return (ERROR);
	}
	(*line)[offset] = '\n';
	tmp = *mem;
	*mem = ft_strdup(*mem + offset + 1);
	free(tmp);
	return (SUCCESS);
}

int	get_next_line(int fd, char **line)
{
	int			offset;
	char		buf[BUFFER_SIZE + 1];
	static char	*mem[OPEN_MAX + 1];

	if (fd < 0 || !line || OPEN_MAX < fd || BUFFER_SIZE < 1)
		return (ERROR);
	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset <= 0)
			break ;
		buf[offset] = '\0';
		if (!save_buf(&mem[fd], buf))
			return (ERROR);
		if (is_new_line(&mem[fd]) != -1)
			return (get_line(&mem[fd], line));
	}
	return (get_line(&mem[fd], line));
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	int ret;
	char *line;

	fd = open("test_file1", O_RDONLY);
	if (fd < 0)
		return (1);
	ret = get_next_line(fd, &line);
	if (ret < 0)
	{
		close(fd);
		return (1);
	}
	printf("Result: %d\n", ret);
	printf("Sentence: %s\n", line);
	free(line);
	close(fd);
	return (0);
}