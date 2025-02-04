/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:58 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 14:00:59 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int data, int index);

int	stack_len(t_stack *stack) //Define a function that calculates and returns the length of a stack
{
	int	count; //To store the node count

	if (!stack) 
		return (0);
	count = 0;
	while (stack) //Loop until the end of the stack is reached
	{
		stack = stack->next; //Move to the next node
		count++;
	}
	return (count);
}

void	initializeStack(t_stack **stack, int *stackValues, int nValues)
{
	t_stack	*new_node;
	t_stack	*current;
	int		i;

	if (!stack || !stackValues || nValues <= 0)
		return ;
	current = NULL;
	i = 0;
	while (i < nValues)
	{
		new_node = create_node(stackValues[i], i);
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

int	isSorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next) //Loop until the end of the stack is reached
	{
		if (stack->data > stack->next->data) //Check if the current value is larger than the next node's value, indicating it is out of sort
			return (0);
		stack = stack->next; //If not, move to the next node for processing
	}
	return (1);
}

int	getLowestNode(t_stack **stack)
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

int	getHighestNode(t_stack **stack)
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

int	getRange(t_stack **stack, int value)
{
	t_stack	*current;
	int		range;

	if (*stack == NULL)
	{
		// Handle empty stack case
		return (-1); // Or any appropriate value to indicate error
	}
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
	// If the loop completes without finding the value
	return (-1); // Or any appropriate value to indicate value not found
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
