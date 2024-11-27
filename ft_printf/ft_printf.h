/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:52:00 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/24 13:31:43 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		int_len(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_int(int i);
int		ft_printf_unsigned_int(unsigned int n);
int		ft_print_hex_lower(unsigned int num);
int		ft_print_hex_upper(unsigned int num);
int		ft_print_hex(unsigned int num, char format);
int		ft_printf_pointer(void *ptr);

#endif