/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:14:10 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/24 12:28:14 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_atoi(const char *str)
{
    int         sign;
    long long   num;

    sign = 1;
    num = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n' ||
     *str == '\v' ||*str == '\f' || *str == '\r')
        str++;
    while (*str == '-' || *str == '+')
    {
        if (*str++ == '-')
            sign *= -1;
    }
    while(ft_isdigit(*str))
    {
        num *= 10;
        num += *str - '0';
        str++;
    }
    return (num * sign);
}