/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:01:59 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/30 23:41:05 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long num)
{
	int			len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			sign;
	long long	num;
	int			len;
	char		*ret;

	num = n;
	sign = 0;
	if (n <= 0)
	{
		num = (long long)n * -1;
		sign = 1;
	}
	len = get_len(num);
	ret = (char *)malloc(len + 1 + sign);
	if (!ret)
		return (NULL);
	len = len + sign;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len--] = num % 10 + '0';
		num /= 10;
	}
	((n < 0) && (ret[0] = '-'));
	return (ret);
}
