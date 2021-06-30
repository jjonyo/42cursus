/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:35:24 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 14:54:34 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (src == dest || !n)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
		return (dest);
	}
	while (n)
	{
		n--;
		dest_ptr[n] = src_ptr[n];
	}
	return (dest);
}
