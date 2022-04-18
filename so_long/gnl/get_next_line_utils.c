/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:45:53 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/18 21:15:40 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	if (!src)
		return (-1);
	if (d_size)
	{
		while (i + 1 < d_size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		ret = 1;
	}
	return (ret);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = gnl_ft_strlen(s1);
	len2 = gnl_ft_strlen(s2);
	ret = (char *)malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	gnl_ft_strlcpy(ret, s1, len1 + 1);
	gnl_ft_strlcpy(ret + len1, s2, len2 + 1);
	return (ret);
}

char	*gnl_ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	if (!s)
		return (NULL);
	len = gnl_ft_strlen(s);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	gnl_ft_strlcpy(ret, s, len + 1);
	return (ret);
}

size_t	gnl_ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	gnl_ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (i);
	return (-1);
}
