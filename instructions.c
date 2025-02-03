/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:35:19 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/03 20:25:58 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;
	int		data;
	int		index;

	if (stack_len(stack) < 2 || !stack)
		return (-1);
	first = *stack;
	next = first->next;
	if (!first && !next)
		return (-1);
	data = first->data;
	index = first->index;
	first->data = next->data;
	first->index = next->index;
	next->data = data;
	next->index = index;
	return (0);
}

int	sa(t_stack **stack_a/*,t_stack **stack_b*/)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_printf(1,"sa\n");
	return (0);
}

int	sb(/*t_stack **stack_a,*/t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	// ft_putendl_fd("sb", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"sb\n");
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_len(stack_a) < 2) || (stack_len(stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	// ft_putendl_fd("ss", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"ss\n");
	return (0);
}

int	push(t_stack **stack_dest, t_stack **stack_origen)
{
	t_stack	*tmp;
	t_stack	*destino;
	t_stack	*origen;

	if (stack_len(stack_origen) == 0)
		return (-1);
	destino = *stack_dest;
	origen = *stack_origen;
	tmp = origen;
	origen = origen->next;
	*stack_origen = origen;
	if (!destino)
	{
		destino = tmp;
		destino->next = NULL;
		*stack_dest = destino;
	}
	else
	{
		tmp->next = destino;
		*stack_dest = tmp;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	// ft_putendl_fd("pa", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"pa\n");
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_printf(1,"pb\n");
	return (0);
}

int rotate(t_stack **stack)
{
    t_stack *top;

    if (!stack || !*stack || !(*stack)->next)
        return (1); // Error: Empty or single-node stack

    top = *stack;
    *stack = top->next; // New top
    (*stack)->prev = NULL;

    t_stack *last = getLast(*stack);
    last->next = top; // Move old top to the end
    top->prev = last;
    top->next = NULL;

    return (0);
}

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf(1,"ra\n");
	return (0);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf(1,"rb\n");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf(1,"rr\n");
	return (0);
}

int reverseRotate(t_stack **stack)
{
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return (-1); // Error

    last = getLast(*stack);
    last->prev->next = NULL; // Second-to-last node becomes new last
    last->next = *stack; // Move last to top
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;

    return (0);
}

int	rra(t_stack **stack_a/*,t_stack **stack_b*/)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	// ft_putendl_fd("rra", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"rra\n");
	return (0);
}

int	rrb(/*t_stack **stack_a,*/t_stack **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	// ft_putendl_fd("rrb", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"rrb\n");
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_len(stack_a) < 2) || (stack_len(stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	// ft_putendl_fd("rrr", 1);
	// imprimir_estado(stack_a,stack_b);
	ft_printf(1,"rrr\n");
	return (0);
}