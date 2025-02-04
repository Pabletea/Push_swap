/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:04:48 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 16:48:12 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	move_a_to_b(t_stack **a, t_stack **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b); 
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
    
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !isSorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !isSorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !isSorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
    int remaining = stack_len(*a);
    if (remaining == 3)
        sort_three(a);
    else if (remaining == 2 && (*a)->data > (*a)->next->data)
    {	
		sa(a);
	}
	while (*b)
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a);
	min_on_top(a);
}