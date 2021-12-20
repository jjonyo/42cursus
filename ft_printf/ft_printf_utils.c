/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:51:02 by jonghpar          #+#    #+#             */
/*   Updated: 2021/12/21 00:03:57 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int is_upper)
{
	char	*hex;
	int		len;

	len = 0;
	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n > 15)
		len = ft_puthex(n / 16, is_upper);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_ptr_to_hex(unsigned long n)
{
	char	*hex;
	int		len;

	len = 0;
	hex = "0123456789abcdef";
	if (n > 15)
		len = ft_ptr_to_hex(n / 16);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	return (ft_putstr("0x") + ft_ptr_to_hex(n));
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = ft_put_unsigned_nbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(n * -1);
	}
	else
	{
		if (n >= 10)
			len = ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}
