/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:06:58 by jonghpar          #+#    #+#             */
/*   Updated: 2021/12/21 00:00:24 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_parse(va_list ap, const char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(ap, int)));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, int), TRUE));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, int), FALSE));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			ret += ft_parse(ap, fmt[++i]);
		else
			ret += ft_putchar(fmt[i]);
	}
	va_end(ap);
	return (ret);
}
