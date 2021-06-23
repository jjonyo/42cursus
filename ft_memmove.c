/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:35:24 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 15:08:18 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *dest_ptr;
    unsigned char   *src_ptr;

    i = 0;
    dest_ptr = (unsigned char *)dest;
    src_ptr = (unsigned char *)src;
    if (dest <= src)
    {
        while(n--)
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