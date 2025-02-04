/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:06:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 21:53:52 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}		

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf(1,"ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf(1,"rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf(1,"rr\n");
}

static void swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;
    first = *head;
    second = first->next;
    third = second->next;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;
    *head = second;
}

void	sa(t_stack	**a)
{
	swap(a);
	ft_printf(1,"sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf(1,"sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf(1,"ss\n");
}
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b); 
	ft_printf(1,"pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf(1,"pb\n");
}

static void rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (stack_len(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void rra(t_stack **a)
{
    rev_rotate(a);
	ft_printf(1,"rra\n");
}
void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf(1,"rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf(1,"rrr\n");
}

void	rotate_both(t_stack **a,t_stack **b,t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a,t_stack **b,t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}