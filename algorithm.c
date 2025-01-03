/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 14:57:12 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sortStack(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !stack_b)
        return;
    if (isSorted(stack_a) || stack_len(stack_a) == 1 || stack_len(stack_a) == 0)
        return; 
    int stackNodes = stack_len(stack_a);

    if (stackNodes == 2)
        sa(stack_a,stack_b);
    else if(stackNodes == 3)
        sort_three(stack_a,stack_b);
    else if (stackNodes == 4)
        sort_four(stack_a,stack_b);
    else if (stackNodes == 5)
        sort_five(stack_a,stack_b);
    else if (stackNodes > 5)
        insertionSort(stack_a, stack_b);
}

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
    if (isSorted(stack_a))
        return;
    int range = getRange(stack_a,getLowestNode(stack_a));
    if (range == 1)
        sa(stack_a,stack_b);
    else if (range == 2)
    {
        rra(stack_a,stack_b);
        rra(stack_a,stack_b);
    }
    else if (range == 3)
        rra(stack_a,stack_b);
    pb(stack_a,stack_b);
    sort_three(stack_a,stack_b);
    pa(stack_a,stack_b);

}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    if (isSorted(stack_a))
        return;
    int lowestNode = getLowestNode(stack_a);
    int range = getRange(stack_a,lowestNode);
    if (range == 1)
        sa(stack_a,stack_b);
    else if (range == 2)
    {
        ra(stack_a,stack_b);
        ra(stack_a,stack_b);
    }
    else if (range == 3)
    {
            rra(stack_a,stack_b);
            rra(stack_a,stack_b);
    }
    else if (range == 5)
        rra(stack_a,stack_b);
    pb(stack_a,stack_b);
    int highestNode = getHighestNode(stack_a);
    range = getRange(stack_a,highestNode);
    ft_printf(1,"Hifghest node = %d\n", highestNode);
    ft_printf(1, "Range = %d\n",range);
    imprimir_estado(stack_a,stack_b);
    if (range == 1)
        sa(stack_a,stack_b);
    else if (range == 2)
    {
        rra(stack_a,stack_b);
        rra(stack_a,stack_b);
    }
    else if (range == 3)
        rra(stack_a,stack_b);
    pb(stack_a,stack_b);
    imprimir_estado(stack_a,stack_b);
    sort_three(stack_a,stack_b);
    pa(stack_a,stack_b);
    ra(stack_a,stack_b);
    pa(stack_a,stack_b);
}

void insertionSort(t_stack **stack_a, t_stack **stack_b)
{
        int chunk_start = 0;
    
    while (chunk_start < 100) {
        int i = 0;
        while (i < 20) {
            int min = chunk_start;
            int max = chunk_start + 19;
            int value = closest_number(stack_a, min, max);

            // Mover el número más cercano al top de Stack A
            while ((*stack_a)->data != value) {
                if (value < stack_len(stack_a) / 2) {
                    ra(stack_a,stack_b);
                } else {
                    rra(stack_a,stack_b);
                }
            }
            pb(stack_a, stack_b);
            i++;
        }
        chunk_start += 20;
    }

    // Mover los números de Stack B a Stack A
    while (*stack_b) {
        pa(stack_a, stack_b);
    }
}


    

