/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 17:30:14 by pabalons         ###   ########.fr       */
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

void sort_three(t_stack **a)
{
    // Validate that the pointer and list are non-null and have at least three nodes.
    if (!a || !(*a) || !((*a)->next) || !((*a)->next->next))
        return;
	
    // Early exit if the stack is already sorted.
    if (isSorted(*a))
        return;

    // Find the biggest node in the stack.
    t_stack *biggest_node = find_max(*a);

    // If the biggest node is at the top, rotate it to the bottom.
    if (*a == biggest_node)
        ra(a);
    // If the biggest node is in the middle, perform a reverse rotate.
    else if ((*a)->next == biggest_node)
        rra(a);

    // Finally, if the top two elements are out of order, swap them.
    if ((*a)->data > (*a)->next->data)
        sa(a);
}





