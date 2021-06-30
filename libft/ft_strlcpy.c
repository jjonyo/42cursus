/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:45:16 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 14:42:34 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t i;
	size_t len;

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
