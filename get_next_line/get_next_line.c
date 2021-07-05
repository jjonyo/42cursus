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
		return (gnl_exit(buf, ERROR));
	}
	free(*mem);
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
		//개행이 있는지 확인함.
		//개행이 있으면 그 전까지 문자열을 line에 담고 SUCCESS return 해야 함.
		//없으면 read 반복
	}
	//여기로 빠져나왔다는 건 이미 파일은 다 읽은 상태라는거
	//따라서 만약 남은 mem중에 개행이 있으면 그 전까지 짤라 line에 담고 SUCCESS 리턴
	//남은 mem중에 개행이 없고, 마지막이라면 마지막 까지 line에 담고 END 리턴
	return (get_eof_line(&mem[fd], line, &buf));
}
