/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:17 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/24 13:31:57 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int num);
int	ft_print_hex_upper(unsigned int num);

int	ft_print_hex(unsigned int num, char format)
{
	if (format == 'X')
		return (ft_print_hex_upper(num));
	else
		return (ft_print_hex_lower(num));
}

int	ft_print_hex_lower(unsigned int num)
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
	write(1, &buffer[i + 1], char_count);
	return (char_count);
}

int	ft_print_hex_upper(unsigned int num)
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
	write(1, &buffer[i + 1], char_count);
	return (char_count);
}
