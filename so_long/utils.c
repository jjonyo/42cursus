/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:04:59 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 11:34:25 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*mem;

	mem = NULL;
	size = ft_strlen(s);
	i = 0;
	mem = malloc(size + 1);
	if (!mem)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		mem[i] = s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	sl_ft_strlcpy(char *dst, char *src, int len)
{
	int	i;
	int	src_len;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*sl_ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*mem;

	mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (sl_ft_strdup(s2));
	else if (s2 == NULL)
		return (sl_ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	mem = malloc(s1_len + s2_len);
	if (!mem)
		return (NULL);
	sl_ft_strlcpy(mem, s1, s1_len + 1);
	sl_ft_strlcpy(mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (mem);
}
