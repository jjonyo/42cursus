/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/05 00:45:32 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*save_buf(char **mem, char *buf)
{
	// mem[fd]에 buf를 저장해야 한다.
	// 만약에 mem[fd]에 이미 문자열이 있다면, 이어붙임
	// 문자열이 없다면 buf를 복사하여 넣기
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
	char	*str;

	str = *mem;
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int get_line(char **mem, char **line)
{

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
			break;
		buf[offset] = '\0';
		if (!save_buf(&mem[fd], buf))
			return (ERROR);
		if (is_new_line(&mem[fd]))
			return (get_line(&mem[fd], line));
	}
	return (get_line(&mem[fd], line));
}

#include <fcntl.h>

int main()
{
	int fd;
	int ret;
	char *line;

	fd = open("test.txt", O_RDONLY);
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
