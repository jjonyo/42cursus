/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:24:43 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/25 00:29:46 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len;
    char    *ret;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    if (!(ret = (char *)malloc(len)))
        return (NULL);
    ft_strlcpy(ret, s1, len);
    ft_strlcpy(ret + ft_strlen(s1), s2, len);
    return (ret);
}