/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:22 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 15:06:24 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t          i;
    unsigned char   *dest_ptr;
    unsigned char   *src_ptr;

    if (n && dest != src)
    {
        i = 0;
        dest_ptr = (unsigned char *)dest;
        src_ptr = (unsigned char *)src;
        while (i < n)
        {
            if (src_ptr[i] == (unsigned char)c)
            {
                dest_ptr[i] = src_ptr[i];
                return (dest + i + 1);
            }
            dest_ptr[i] = src_ptr[i];
            i++;
        }
    }
    return (NULL);
}