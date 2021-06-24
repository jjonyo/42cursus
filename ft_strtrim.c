/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:30:05 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 01:09:06 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char *ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t j;

    if (!s1 || !set)
        return (NULL);
    i = 0;
    j = ft_strlen(s1) - 1;
    while (i <= j && ft_strrchr(set, s1[i]))
        i++;
}
//https://github.com/dcavalei/libft/blob/main/ft_strtrim.c