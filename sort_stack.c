/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:04:48 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 15:34:12 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a);
}

static void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b); 
}

static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->data != find_min(*a)->data) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
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
    imprimir_estado(a,b);
    sleep(5);
    printf("..............\n");
    sleep(1);
	sort_three(a);
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a);
	min_on_top(a);
    imprimir_estado(a,b);
    sleep(4);
}