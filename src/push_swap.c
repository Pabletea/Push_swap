/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:59 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/06 12:33:25 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		process_arguments(char *mega_argv, t_stack **stack_a,
			t_stack **stack_b);
void	print_stack(t_stack *stack);

int	main(int argc, char *argv[])
{
	char	*mega_argv;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (-1);
	mega_argv = arguments_union(argv);
	if (!process_arguments(mega_argv, &stack_a, &stack_b))
		return (1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

int	allocate_stack_values(int **stack_values, int size, char *mega_argv,
		char **valores_argumentos)
{
	*stack_values = (int *)malloc(sizeof(int) * size);
	if (!*stack_values)
	{
		free_all_memory(mega_argv, valores_argumentos);
		return (0);
	}
	return (1);
}

int	convert_arguments_to_int(char **valores_argumentos, int *stack_values,
		int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_values[i] = ft_atoi(valores_argumentos[i]);
		i++;
	}
	return (1);
}

int	parse_and_validate(char *mega_argv, char ***valores_argumentos,
		int **stack_values)
{
	int	size;

	size = 0;
	*valores_argumentos = ft_split(mega_argv, ' ');
	if (!check_arguments(*valores_argumentos))
	{
		free_all_memory(mega_argv, *valores_argumentos);
		return (0);
	}
	while ((*valores_argumentos)[size] != NULL)
		size++;
	if (!allocate_stack_values(stack_values, size, mega_argv,
			*valores_argumentos))
		return (0);
	convert_arguments_to_int(*valores_argumentos, *stack_values, size);
	free_all_memory(mega_argv, *valores_argumentos);
	if (check_duplicates(*stack_values, size))
	{
		ft_printf(2, "Error\n");
		free(*stack_values);
		return (0);
	}
	return (size);
}

int	process_arguments(char *mega_argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**valores_argumentos;
	int		*stack_values;
	int		size;

	size = parse_and_validate(mega_argv, &valores_argumentos, &stack_values);
	if (size == 0)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	initialize_stack(stack_a, stack_values, size);
	free(stack_values);
	return (1);
}
