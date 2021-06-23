/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:58:48 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/23 16:03:46 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char    *ft_strchr(const char *str, int c)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == (unsigned char)c)
            return ((char *)(str + i));
        i++;
    }
    if (str[i] == (unsigned char)c)
        return ((char *)(str + i));
    return (NULL);
}