/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:03:53 by jonghpar          #+#    #+#             */
/*   Updated: 2021/12/20 22:07:04 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

# define TRUE 1
# define FALSE 0

int ft_printf(const char *fmt, ...);
int ft_parse(va_list ap, const char c);
int ft_putnbr(int n);
int ft_put_unsigned_nbr(unsigned int n);
int ft_putstr(char *str);
int ft_putptr(void *ptr);
int ft_ptr_to_hex(unsigned long n);
int ft_puthex(unsigned int n, int is_upper);
int ft_putchar(int c);

#endif