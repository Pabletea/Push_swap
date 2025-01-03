/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 10:24:25 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **stack_a,t_stack **stack_b)
{
    t_stack *current = *stack_a;


    if (current->data > current->next->data && current->data > current->next->next->data)
        ra(stack_a,stack_b);
    else if (current->next->data > current->data && current->next->data > current->next->next->data)
        rra(stack_a,stack_b);

    current = *stack_a;
    if (current->data > current->next->data)
        sa(stack_a,stack_b);
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{
    if(isSorted(stack_a))
        return;
    pb(stack_a,stack_b);
    pb(stack_a,stack_b);
    
}
