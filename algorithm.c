/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 21:57:44 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stackNodes;

	if (!stack_a || !stack_b)
		return ;
	if (isSorted(*stack_a) || stack_len(*stack_a) == 1
		|| stack_len(*stack_a) == 0)
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
	t_stack	*biggest_node;

	if (!a || !(*a) || !((*a)->next) || !((*a)->next->next))
		return ;
	if (isSorted(*a))
		return ;
	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
