/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:04:12 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 21:49:39 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack) 
{
	long			min; 
	t_stack	*min_node; 

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*find_last(t_stack *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}
t_stack	*get_cheapest(t_stack *stack) 
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapiest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
void	prep_for_push(t_stack **stack,
						t_stack *top_node,
						char stack_name) 
{
	while (*stack != top_node) 
	{
		if (stack_name == 'a') 
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') 
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}