/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:19:04 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 14:27:57 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

 void   *ft_memcpy(void *dest, const void *src, size_t n)
 {
     int i;
     unsigned char  *dest_ptr;
     unsigned char  *src_ptr;

     if (n && dest != src)
     {
        i = 0;
        dest_ptr = dest;
        src_ptr = src;
        while (i < n)
        {
           dest_ptr[i] = src_ptr[i];
           i++;
        }
     }
     return (dest);
 }