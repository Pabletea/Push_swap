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
    else if (stackNodes >= 5)
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
    int len_a;

    len_a = stack_len(stack_a);

    if (len_a-- > 3 && !isSorted(stack_a))
        pb (stack_a,stack_b);
    if (len_a-- > 3 && !isSorted(stack_a))
        pb (stack_a,stack_b);
    while(len_a-- > 3 && !isSorted(stack_a))
    {

    }

}

void init_nodes_a(t_stack *a,t_stack *b)
{

}

void current_index(t_stack **stack_a,t_stack *stack)
{
    int i;
    int median;
    i = 0;
    if (!stack)
        return;
    median = stack_len(stack_a);
    while(stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        i++;
    }
}

static void set_target_a(t_stack **stack_a, t_stack **stack_b,t_stack *a, t_stack *b)
{

}


    

