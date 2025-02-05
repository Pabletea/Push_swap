/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:59 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/05 10:32:19 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		getValues(int ar, char *av[]);
static void	free_all_memory(char *argv_union, char **arr_arguments);
static int	check_arguments(char **argv);

int	main(int argc, char *argv[])
{
	char	*mega_argv;
	char	**valores_argumentos;
	int		size;
	int		*stack_values;
	int		i;
	t_stack	**stack_a;
	t_stack	**stack_b;

	mega_argv = NULL;
	valores_argumentos = NULL;
	if (argc < 2)
		return (-1);
	mega_argv = arguments_union(argv);
	valores_argumentos = ft_split(mega_argv, ' ');
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	if (!check_arguments(valores_argumentos))
		return (free_all_memory(mega_argv, valores_argumentos), 0);
	size = 0;
	while (valores_argumentos[size] != NULL)
		size++;
	stack_values = (int *)malloc(sizeof(int) * size);
	if (!stack_values)
		return (1);
	i = 0;
	while (i < size)
	{
		stack_values[i] = ft_atoi(valores_argumentos[i]);
		i++;
	}
	initialize_stack(stack_a, stack_values, size);
	if (stack_values != NULL)
	{
		if (is_sorted(*stack_a))
		{
			free_stack(*stack_a);
			free_stack(*stack_b);
			free(stack_a);
			free(stack_b);
			return (0);
		}
		else
			sort_stack(stack_a, stack_b);
	}
	else
	{
		ft_printf(2, "Error\n");
	}
	free(stack_values);
	free_stack(*stack_a);
	free_stack(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

static int	check_arguments(char **argv)
{
	int	i;

	i = 0;
	if (!argv[i])
		return (ft_printf(2, "Error: No arguments provided\n"), 0);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf(2, "Error: incorrect arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	free_all_memory(char *argv_union, char **arr_arguments)
{
	char	**temp;

	temp = arr_arguments;
	if (argv_union != NULL)
		free(argv_union);
	if (arr_arguments != NULL)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
	}
	free(arr_arguments);
}
