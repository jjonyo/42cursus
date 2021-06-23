/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:37:00 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 15:39:28 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    *memchr(const void *s, int c, size_t n)
{
    size_t          i;
    unsigned char   *p;

    i = 0;
    p = (unsigned char *)s;
    while (i < n)
    {
        if (p[i] == (unsigned char)c)
            return (p + i);
        i++;
    }
    return (NULL);
}