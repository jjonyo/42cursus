/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:03:56 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 14:43:57 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t i;

	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
	}
	return (NULL);
}
