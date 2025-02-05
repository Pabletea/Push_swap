/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:58 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/05 09:54:41 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int data, int index);

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	initialize_stack(t_stack **stack, int *stack_values, int nValues)
{
	t_stack	*new_node;
	t_stack	*current;
	int		i;

	if (!stack || !stack_values || nValues <= 0)
		return ;
	current = NULL;
	i = 0;
	while (i < nValues)
	{
		new_node = create_node(stack_values[i], i);
		if (!new_node)
			return ;
		if (*stack == NULL)
			*stack = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_lowest_node(t_stack **stack)
{
	t_stack	*current;
	int		minimum;

	if (*stack == NULL)
		return (INT_MAX);
	current = *stack;
	minimum = current->data;
	while (current != NULL)
	{
		if (current->data < minimum)
		{
			minimum = current->data;
		}
		current = current->next;
	}
	return (minimum);
}

int	get_highest_node(t_stack **stack)
{
	t_stack	*current;
	int		maximun;

	if (*stack == NULL)
		return (INT_MAX);
	current = *stack;
	maximun = current->data;
	while (current != NULL)
	{
		if (current->data > maximun)
		{
			maximun = current->data;
		}
		current = current->next;
	}
	return (maximun);
}
