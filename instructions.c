/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:35:19 by pabalons          #+#    #+#             */
/*   Updated: 2024/12/09 12:35:19 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack a)
{
    t_node *node;
    int temp;

    if (stack_len(a)  >= 2)
    {
        node = a.top;
        temp = node->data;
        node->data = node->next->data;
        node->next->data = temp;
    }
}

void sb(t_stack b)
{
    sa(b);
}

void ss(t_stack a, t_stack b)
{
    sa(a);
    sb(b);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->top == NULL) {
        return;
    }

    t_node *temp = b->top;
    b->top = b->top->next;

    temp->next = a->top;
    a->top = temp;
}


void pb(t_stack *a, t_stack *b)
{
    if (a->top == NULL)
        return;

    t_node *temp = a->top;
    a->top = a->top->next;

    temp->next = b->top;
    b->top = temp;

}

void ra(t_stack a){

    if (a.top == NULL || a.top->next == NULL) 
        return;

    t_node *first = a.top;
    a.top = a.top->next;

    t_node *current = a.top;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = first;
    first->next = NULL;

}

void rb(t_stack b)
{
    if (b.top == NULL || b.top->next == NULL) 
        return;

    t_node *first = b.top;
    b.top = b.top->next;

    t_node *current = b.top;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = first;
    first->next = NULL;

}

void rr(t_stack a, t_stack b)
{
    if (a.top == NULL || b.top == NULL)
        return;
    ra(a);
    rb(b);
}

void rra(t_stack a)
{
    if (a.top == NULL || a.top->next == NULL)
        return;

    t_node *current = a.top;
    t_node *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = a.top;
    a.top = current;
}

void rrb(t_stack b)
{
    if (b.top == NULL || b.top->next == NULL)
        return;

    t_node *current = b.top;
    t_node *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = b.top;
    b.top = current;
}

void rrr(t_stack a, t_stack b)
{
    if (a.top == NULL || b.top == NULL)
        return;
    rra(a);
    rrb(b);
}