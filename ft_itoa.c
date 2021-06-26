/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:01:59 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/26 13:47:23 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			sign;
	long long	num;
	int			len;
	char		*ret;

	sign = n <= 0 ? 1 : 0;
	num = n < 0 ? (long long)n * -1 : n;
	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	if (!(ret = (char *)malloc(len + 1 + sign)))
		return (NULL);
	num = n < 0 ? (long long)n * -1 : n;
	len = len + sign;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len--] = num % 10 + '0';
		num /= 10;
	}
	ret[0] = n < 0 ? '-' : ret[0];
	return (ret);
}
