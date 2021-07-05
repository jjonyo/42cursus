/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:15:43 by jonghpar          #+#    #+#             */
/*   Updated: 2021/07/05 16:49:54 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	str_len;
	char	*ret;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (len > str_len)
		len = str_len;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	n = ft_strlen(s);
	i = 0;
	while (i < len && i + start < n)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
