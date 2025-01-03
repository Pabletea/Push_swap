/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:35:19 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 10:21:26 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*next;
	int		data;
	int		index;

	if (stack_len(stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_printf("Error en el swap");
	data = top->data;
	index = top->index;
	top->data = next->data;
	top->index = next->index;
	next->data = data;
	next->index = index;
	return (0);
}

int	sa(t_stack **stack_a,t_stack **stack_b)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}

int	sb(t_stack **stack_a,t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_len(stack_a) < 2) || (stack_len(stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
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
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	imprimir_estado(stack_a,stack_b);
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (stack_len(stack) < 2)
		return (-1);
	top = *stack;
	last = getLast(top);
	*stack = top->next;
	top->next = NULL;
	last->next = top;
	return (0);
}

int	ra(t_stack **stack_a,t_stack **stack_b)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}

int	rb(t_stack **stack_a,t_stack **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	imprimir_estado(stack_a,stack_b);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_len(stack_a) < 2) || (stack_len(stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}

int	reverseRotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (stack_len(stack) < 2)
		return (-1);
	top = *stack;
	last = getLast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_stack **stack_a,t_stack **stack_b)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}

int	rrb(t_stack **stack_a,t_stack **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	imprimir_estado(stack_a,stack_b);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_len(stack_a) < 2) || (stack_len(stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	imprimir_estado(stack_a,stack_b);
	ft_printf("------------------------\n");
	return (0);
}