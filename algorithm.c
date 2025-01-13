/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/13 13:27:42 by pabalons         ###   ########.fr       */
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
                sa(stack_a/*,stack_b*/);
    else if(stackNodes == 3)
        sort_three(stack_a/*,stack_b*/);
    else if (stackNodes == 4)
        sort_four(stack_a,stack_b);
    else if (stackNodes == 5)
        sort_five(stack_a,stack_b);
    else if (stackNodes > 5)
        sortAlgorithm(stack_a,stack_b);
}

void sort_three(t_stack **stack_a/*,t_stack **stack_b*/)
{
    // ft_printf(1,"Sort three\n");
    t_stack *current = *stack_a;

    if (current->data > current->next->data && current->data > current->next->next->data)
        ra(stack_a/*,stack_b*/);
    else if (current->next->data > current->data && current->next->data > current->next->next->data)
        rra(stack_a/*,stack_b*/);

    current = *stack_a;
    if (current->data > current->next->data)
                sa(stack_a/*,stack_b*/);
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{
    // ft_printf(1,"Sort four\n");
    if (isSorted(stack_a))
        return;
    int range = getRange(stack_a,getLowestNode(stack_a));
    if (range == 1)
                sa(stack_a/*,stack_b*/);
    else if (range == 2)
    {
        rra(stack_a/*,stack_b*/);
        rra(stack_a/*,stack_b*/);
    }
    else if (range == 3)
        rra(stack_a/*,stack_b*/);
    pb(stack_a,stack_b);
    sort_three(stack_a/*,stack_b*/);
    pa(stack_a,stack_b);

}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    // ft_printf(1,"Sort five\n");
    if (isSorted(stack_a))
        return;
    int lowestNode = getLowestNode(stack_a);
    int range = getRange(stack_a,lowestNode);
    if (range == 1)
                sa(stack_a/*,stack_b*/);
    else if (range == 2)
    {
        ra(stack_a/*,stack_b*/);
        ra(stack_a/*,stack_b*/);
    }
    else if (range == 3)
    {
            rra(stack_a/*,stack_b*/);
            rra(stack_a/*,stack_b*/);
    }
    else if (range == 5)
        rra(stack_a/*,stack_b*/);
    pb(stack_a,stack_b);
    int highestNode = getHighestNode(stack_a);
    range = getRange(stack_a,highestNode);
    // ft_printf(1,"Hifghest node = %d\n", highestNode);
    // ft_printf(1, "Range = %d\n",range);
    // imprimir_estado(stack_a,stack_b);
    if (range == 1)
                sa(stack_a/*,stack_b*/);
    else if (range == 2)
    {
        rra(stack_a/*,stack_b*/);
        rra(stack_a/*,stack_b*/);
    }
    else if (range == 3)
        rra(stack_a/*,stack_b*/);
    pb(stack_a,stack_b);
    // imprimir_estado(stack_a,stack_b);
    sort_three(stack_a/*,stack_b*/);
    pa(stack_a,stack_b);
    ra(stack_a/*,stack_b*/);
    pa(stack_a,stack_b);
}

void sortAlgorithm(t_stack **stack_a, t_stack **stack_b)
{
    // ft_printf(1,"Sort MORE");
    while (!isSorted(stack_a)) {
        // Push the smallest elements from `a` to `b` in chunks
        while (stack_len(stack_a) > 3) {
            int lowest = getLowestNode(stack_a);
            while ((*stack_a)->data != lowest) {
                if (getLowestNode(stack_a) < stack_len(stack_a) / 2)
                    ra(stack_a/*,stack_b*/);  // Rotate until the smallest element is on top
                else
                    rra(stack_a/*,stack_b*/); // Reverse rotate for efficiency
            }
            pb(stack_a, stack_b); // Push the smallest element to stack `b`
        }
    
        if (!isSorted(stack_a)) {
            if ((*stack_a)->data > (*stack_a)->next->data)
                        sa(stack_a/*,stack_b*/);
            if ((*stack_a)->next->data > (*stack_a)->next->next->data) {
                ra(stack_a/*,stack_b*/);
                        sa(stack_a/*,stack_b*/);
                rra(stack_a/*,stack_b*/);
            }
            if ((*stack_a)->data > (*stack_a)->next->data)
                        sa(stack_a/*,stack_b*/);
        }
        while (stack_len(stack_b) > 0) {
            int highest = getHighestNode(stack_b);
            while ((*stack_b)->data != highest) {
                if (getHighestNode(stack_b) < stack_len(stack_b) / 2)
                    rb(/*stack_a,*/stack_b);  // Rotate until the highest element is on top
                else
                    rrb(/*stack_a,*/stack_b); // Reverse rotate for efficiency
            }
            pa(stack_a, stack_b); // Push the highest element back to stack `a`
        }
    }
}



    

