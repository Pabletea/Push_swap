/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:17 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 13:05:08 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(int fd, unsigned int num);
int	ft_print_hex_upper(int fd, unsigned int num);

int	ft_print_hex(int fd, unsigned int num, char format)
{
	if (format == 'X')
		return (ft_print_hex_upper(fd, num));
	else
		return (ft_print_hex_lower(fd, num));
}

int	ft_print_hex_lower(int fd, unsigned int num)
{
	char	*hex_digits;
	char	buffer[9];
	int		i;
	int		char_count;

	hex_digits = "0123456789abcdef";
	i = 8;
	char_count = 0;
	buffer[i--] = '\0';
	if (num == 0)
	{
		buffer[i--] = '0';
		char_count++;
	}
	while (num > 0)
	{
		buffer[i--] = hex_digits[num % 16];
		num /= 16;
		char_count++;
	}
	write(fd, &buffer[i + 1], char_count);
	return (char_count);
}

int	ft_print_hex_upper(int fd, unsigned int num)
{
	char	*hex_digits;
	char	buffer[9];
	int		i;
	int		char_count;

	hex_digits = "0123456789ABCDEF";
	i = 8;
	char_count = 0;
	buffer[i--] = '\0';
	if (num == 0)
	{
		buffer[i--] = '0';
		char_count++;
	}
	while (num > 0)
	{
		buffer[i--] = hex_digits[num % 16];
		num /= 16;
		char_count++;
	}
	write(fd, &buffer[i + 1], char_count);
	return (char_count);
}
