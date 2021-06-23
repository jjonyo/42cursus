/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:03:43 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 13:58:35 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    *ft_memset(void *dest, int c, size_t n)
{
    size_t          i;
    unsigned char   *p;
    
    i = 0;
    p = dest;
    while(i < n)
    {
        p[i] = (unsigned char)c;
        i++;
    }

    return (dest);
}