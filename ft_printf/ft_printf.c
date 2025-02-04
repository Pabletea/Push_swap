/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:06:51 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 13:11:37 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	print_value(int fd, va_list args, const char *str, int count);
int	ft_printf_char(int fd, char c);
int	ft_printf_str(int fd, char *str);
int	ft_printf_int(int fd, int i);
int	ft_printf_unsigned_int(int fd, unsigned int n);

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count = print_value(fd, args, format, count);
	va_end(args);
	return (count);
}

int	print_value(int fd, va_list args, const char *str, int count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				count += ft_printf_char(fd, '%');
			else if (*str == 'c')
				count += ft_printf_char(fd, va_arg(args, int));
			else if (*str == 's')
				count += ft_printf_str(fd, va_arg(args, char *));
			else if (*str == 'u')
				count += ft_printf_unsigned_int(fd, va_arg(args, unsigned int));
			else if (*str == 'd' || *str == 'i')
				count += ft_printf_int(fd, va_arg(args, int));
			else if (*str == 'x' || *str == 'X')
				count += ft_print_hex(fd, va_arg(args, unsigned int), *str);
			else if (*str == 'p')
				count += ft_printf_pointer(fd, va_arg(args, void *));
		}
		else
			count += ft_printf_char(fd, *str);
		str++;
	}
	return (count);
}
