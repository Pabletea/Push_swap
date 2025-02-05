/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:54:13 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/05 12:04:04 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(t_stack **stack, int value)
{
	t_stack	*current;
	int		range;

	if (*stack == NULL)
		return (-1);
	current = *stack;
	range = 0;
	while (current != NULL)
	{
		if (current->data == value)
		{
			return (range);
		}
		range++;
		current = current->next;
	}
	return (-1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

t_stack	*create_node(int data, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

int	check_arguments(char **argv)
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

void	free_all_memory(char *argv_union, char **arr_arguments)
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
