/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2024/12/03 12:34:07 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void sort_three(t_stack *a)
{
    t_node *current;

    if (!a || !a->top || !a->top->next || !a->top->next->next)
        return; // Asegurarse de que hay exactamente tres elementos

    current = a->top;

    // Caso 1: 3 2 1 (completamente desordenado)
    if (current->data > current->next->data && current->data > current->next->next->data)
        ra(a);
    // Caso 2: 2 3 1
    else if (current->next->data > current->data && current->next->data > current->next->next->data)
        rra(a);

    // Ahora los dos primeros deben ordenarse si es necesario
    current = a->top;
    if (current->data > current->next->data)
        sa(a);
}