/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:59:56 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 14:32:26 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *dest, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = dest;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}