/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:05:45 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/01 00:25:36 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	*free_memory(char **ret, int i)
{
	while (i >= 0)
	{
		if (ret[i])
		{
			free(ret[i]);
			ret[i] = NULL;
		}
		i--;
	}
	if (ret)
	{
		free(ret);
		ret = NULL;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!s || !ret)
		return (free_memory(ret, i - 1));
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			ret[i++] = ft_substr(tmp, 0, s - tmp);
			if (!ret[i - 1])
				return (free_memory(ret, i - 1));
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
