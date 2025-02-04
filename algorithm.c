/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 15:00:47 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stackNodes;

	if (!stack_a || !stack_b)
		return ;
	if (isSorted(*stack_a) || stack_len(*stack_a) == 1 || stack_len(*stack_a) == 0)
		return ;
	stackNodes = stack_len(*stack_a);
	if (stackNodes == 2) 
		sa(stack_a);
	else if (stackNodes == 3)
		sort_three(stack_a);
	else
		sort_stacks(stack_a, stack_b);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->data > (*a)->next->data) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a); //If so, simply swap the top and second nodes

}



