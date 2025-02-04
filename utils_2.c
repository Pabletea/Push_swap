/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:56:40 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 23:19:36 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid_integer_value(char *str);
long	ft_atol(const char *nptr);

char	*arguments_union(char **argv)
{
	int		i;
	char	*union_str;
	char	*temp_str;

	i = 1;
	union_str = ft_calloc(1, 1);
	if (!union_str)
		return (NULL);
	union_str[0] = '\0';
	while (argv[i])
	{
		temp_str = ft_strjoin(union_str, " ");
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		temp_str = ft_strjoin(union_str, argv[i]);
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		i++;
	}
	return (union_str);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || strlen(str) == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_valid_integer_value(str));
}

int	is_valid_integer_value(char *str)

{
	long num;
	long    check_num;

	num = ft_atoi(str);
	check_num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	else if (num != check_num)
		return (0);
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		s;
	long	n;

	i = 0;
	n = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * s);
}

void	convert_strings_to_integers(const char *strArray[], int intArray[],
		int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		intArray[i] = ft_atoi(strArray[i]);
		i++;
	}
}
