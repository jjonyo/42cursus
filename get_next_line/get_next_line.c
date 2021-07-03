/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:46:09 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/03 14:03:03 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	save_buf(int fd, char **mem, char *buf)
{
	// mem[fd]에 buf를 저장해야 한다.
	// 만약에 mem[fd]에 이미 문자열이 있다면, 이어붙임
	// 문자열이 없다면 buf를 복사하여 넣기
	char	*tmp;

	if (mem[fd])
	{
		tmp = mem[fd];
		mem[fd] = ft_strjoin(mem[fd], buf);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		mem[fd] = ft_strdup(buf);
	}
	if (!mem[fd])
		return (0);
	return (1);
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
		save_buf(fd, mem, buf);
		//mem에 buf문자열 저장
		//new line 검사
	}
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
