/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:06:51 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/24 13:48:01 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_value(va_list args, const char *str, int count);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_int(int i);
int	ft_printf_unsigned_int(unsigned int n);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count = print_value(args, format, count);
	va_end(args);
	return (count);
}

int	print_value(va_list args, const char *str, int count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				count += ft_printf_char('%');
			else if (*str == 'c')
				count += ft_printf_char(va_arg(args, int));
			else if (*str == 's')
				count += ft_printf_str(va_arg(args, char *));
			else if (*str == 'u')
				count += ft_printf_unsigned_int(va_arg(args, unsigned int));
			else if (*str == 'd' || *str == 'i')
				count += ft_printf_int(va_arg(args, int));
			else if (*str == 'x' || *str == 'X')
				count += ft_print_hex(va_arg(args, unsigned int), *str);
			else if (*str == 'p')
				count += ft_printf_pointer(va_arg(args, void *));
		}
		else
			count += ft_printf_char(*str);
		str++;
	}
	return (count);
}
