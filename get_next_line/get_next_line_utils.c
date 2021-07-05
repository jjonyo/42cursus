/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:45:53 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/05 13:29:18 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	while (src[len])
		len++;
	if (d_size)
	{
		while (i + 1 < d_size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(len);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len);
	ft_strlcpy(ret + ft_strlen(s1), s2, len);
	return (ret);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}