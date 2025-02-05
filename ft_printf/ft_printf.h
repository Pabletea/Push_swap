/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:52:00 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 13:11:19 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(int fd, char const *format, ...);
int		int_len(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_printf_char(int fd, char c);
int		ft_printf_str(int fd, char *str);
int		ft_printf_int(int fd, int i);
int		ft_printf_unsigned_int(int fd, unsigned int n);
int		ft_print_hex_lower(int fd, unsigned int num);
int		ft_print_hex_upper(int fd, unsigned int num);
int		ft_print_hex(int fd, unsigned int num, char format);
int		ft_printf_pointer(int fd, void *ptr);

#endif