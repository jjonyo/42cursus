/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:11:55 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/26 13:01:17 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	i;
	char	*ret;
	
	if (!s || !(ret = (char *)malloc(len + 1)))
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
