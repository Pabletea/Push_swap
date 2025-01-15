/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:34:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/15 15:24:27 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void current_index(t_stack **stack_a);
void init_nodes_a(t_stack **stack_a,t_stack **stack_b);
static void set_target_a(t_stack **stack_a, t_stack **stack_b);
static void cost_analysis_a(t_stack **stack_a,t_stack ** stack_b);
static void set_cheapest(t_stack **stack);
static void move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void init_nodes_b(t_stack **stack_a, t_stack **stack_b,t_stack *a, t_stack *b);
void rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapiest_node);
t_stack *get_cheapest(t_stack **stack);
void rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapiest_node);
void prep_for_push(t_stack **stack,t_stack *top_node,char stack_name);
t_stack *find_min(t_stack *stack);
void set_target_b(t_stack *a, t_stack *b);
t_stack *find_max(t_stack *stack);

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
    imprimir_estado(stack_a,stack_b);
    printf("LEN: %d",len_a);
    exit(1);

    if (len_a-- > 3 && !isSorted(stack_a))
        pb (stack_a,stack_b);     
    if (len_a-- > 3 && !isSorted(stack_a))
        pb (stack_a,stack_b);
    while(len_a-- > 3 && !isSorted(stack_a))
    {
        init_nodes_a(stack_a,stack_b);
        move_a_to_b(stack_a,stack_b);
    }
    sort_three(stack_a);
    while(*stack_b)
    {
        init_nodes_b(stack_a,stack_b,*stack_a,*stack_b);
    }
    current_index(stack_a);
}

void init_nodes_a(t_stack **stack_a,t_stack **stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_a(stack_a,stack_b);
    cost_analysis_a(stack_a,stack_b);
    set_cheapest(stack_a);
}

static void current_index(t_stack **stack_a)
{
    int i;
    int median;
    i = 0;
    if (!stack_a)
        return;
    median = stack_len(stack_a);
    t_stack *node = *stack_a;
    while(node)
    {
        node->index = i;
        if (i <= median)
            node->above_median = 1;
        else
            node->above_median = 0;
        node = node->next;
        i++;
    }
}

static void set_target_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_b;
    t_stack *target_node;
    int    best_match_value;
    t_stack *node = *stack_a;

    while(node)
    {
        best_match_value = INT_MIN;
        current_b = *stack_b;
        while(current_b)
        {
            if (current_b->data < node->data && current_b->data > best_match_value)
            {
                best_match_value = current_b->data;
                target_node = current_b;   
            }
            current_b = current_b->next;
        }
        if (best_match_value == INT_MIN)
            node->target_node = find_max(*stack_b);
        else
            node->target_node = target_node;
        node = node->next;
    }
}

static void cost_analysis_a(t_stack **stack_a,t_stack ** stack_b)
{
    int len_a;
    int len_b;

    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);
    t_stack *a = *stack_a;

    while(a)
    {
        a->push_cost = a->index;
        if (!(a->above_median))
            a->push_cost = len_a - (a->index);

        if (a->target_node->above_median == 1)
        {
            ft_printf(1,"CASO 1");
            a->push_cost += a->target_node->index;
        }
        else
        {
            ft_printf(1,"CASO 2");
            a->push_cost += len_b - (a->target_node->index);
        }
        a = a->next;
    }
}

static void set_cheapest(t_stack **stack)
{
    t_stack *current = *stack;
    int cheapiest_value;
    t_stack *cheapiest_node;
    if (!stack)
        return;
    cheapiest_value = INT_MAX;
    while(current)
    {
        if (current->push_cost < cheapiest_value)
        {
            cheapiest_value = current->push_cost;
            cheapiest_node = current;
        }
        current = current->next;
        cheapiest_node->is_cheapiest = 1;
    }
}


static void move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapiest_node;

    cheapiest_node = get_cheapest(stack_a);
    if (cheapiest_node->above_median && cheapiest_node->target_node->above_median)
        rotate_both(stack_a,stack_b,cheapiest_node);
    else if (!(cheapiest_node->above_median) && !(cheapiest_node->target_node->above_median))
        rev_rotate_both(stack_a,stack_b,cheapiest_node);
    prep_for_push(stack_a,cheapiest_node, 'a');
    prep_for_push(stack_b,cheapiest_node, 'b');
    pb(stack_a,stack_b);


}


t_stack *get_cheapiest(t_stack **stack)
{
    if (!stack)
        return (NULL);
    t_stack *current = *stack;
    while(current)
    {
        if (current->is_cheapiest)
            return(current);
        current = current->next;
    }
    return (NULL);
}

void rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapiest_node)
{
    t_stack *current_a = *stack_a;
    t_stack *current_b = *stack_b;
    while(current_b != cheapiest_node->target_node && current_a != cheapiest_node)
        rr(stack_a,stack_b);
    current_index(stack_a);
    current_index(stack_b);

}

void prep_for_push(t_stack **stack,t_stack *top_node,char stack_name)
{
    t_stack *current = *stack;
    while(current)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

void init_nodes_b(t_stack **stack_a, t_stack **stack_b,t_stack *a, t_stack *b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_b(a,b);

}


    

t_stack *get_cheapest(t_stack **stack)
{
    if (!stack)
        return (NULL);
    t_stack *node = *stack;
    while(node)
    {
        if (node->is_cheapiest)
            return (node);
        node = node->next;
    }
    return (NULL);
}


void rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapiest_node)
{   
    while(*stack_b != cheapiest_node->target_node && *stack_a != cheapiest_node)
        rrr(stack_a,stack_a);
    current_index(stack_a);
    current_index(stack_b);
}


void set_target_b(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target_node;
    int     best_match_index;

    while(b)
    {
        best_match_index = INT_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->data > b->data && current_a->data < best_match_index)
            {
                best_match_index = current_a->data;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == INT_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;
        
    }
}

t_stack *find_min(t_stack *stack)
{
    int min;
    t_stack *min_node;

    if (!stack)
        return (NULL);
    min = INT_MAX;
    while(stack)
    {
        if (stack->data < min)
        {
            min = stack->data;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_stack *find_max(t_stack *stack)
{
    int max;
    t_stack *max_node;

    if (!stack)
        return (NULL);
    max = INT_MIN;
    while(stack)
    {
        if (stack->data > max)
        {
            max = stack->data;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}