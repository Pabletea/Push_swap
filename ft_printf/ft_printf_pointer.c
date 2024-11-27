/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:36:51 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/24 13:30:59 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned long num);

int	ft_printf_pointer(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	print_hex((unsigned long)ptr);
	address = (unsigned long)ptr;
	while (address != 0)
	{
		address /= 16;
		count++;
	}
	return (count + 2);
}

static void	print_hex(unsigned long num)
{
	const char	*hex_digits = "0123456789abcdef";
	char		buffer[16];
	int			i;

	i = 15;
	while (num != 0)
	{
		buffer[i--] = hex_digits[num % 16];
		num /= 16;
	}
	write(1, "0x", 2);
	write(1, &buffer[i + 1], 15 - i);
}
