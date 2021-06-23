/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:59:56 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 14:02:37 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    ft_bzero(void *dest, size_t n)
{
    size_t          i;
    unsigned char   *p;
    
    i = 0;
    p = dest;
    while(i < n)
    {
        p[i] = 0;
        i++;
    }
}