/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:36:51 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 13:12:13 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(int fd, unsigned long num);

int	ft_printf_pointer(int fd, void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	print_hex(fd, (unsigned long)ptr);
	address = (unsigned long)ptr;
	while (address != 0)
	{
		address /= 16;
		count++;
	}
	return (count + 2);
}

static void	print_hex(int fd, unsigned long num)
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
	write(fd, "0x", 2);
	write(fd, &buffer[i + 1], 15 - i);
}
