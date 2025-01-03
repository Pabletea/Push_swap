/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 09:21:27 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **stack)
{
    t_stack *current = *stack;


    if (current->data > current->next->data && current->data > current->next->next->data)
        ra(stack);
    else if (current->next->data > current->data && current->next->data > current->next->next->data)
        rra(stack);

    current = *stack;
    if (current->data > current->next->data)
        sa(stack);
}
