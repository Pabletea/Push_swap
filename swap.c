/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:59:32 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/05 10:15:20 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!head || !*head || !(*head)->next)
		return ;
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

void	sa(t_stack **a)
{
	swap(a);
	ft_printf(1, "sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf(1, "sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
}
