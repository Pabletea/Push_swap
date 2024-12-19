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

//Intercambia los dos primeros elementos del stack a
void sa(t_stack *a)
{
    t_node *node;
    int temp;

    if (stack_len(a)  >= 2)
    {
        node = a->top;
        temp = node->data;
        node->data = node->next->data;
        node->next->data = temp;
    }
}

//Intercambia los dos primeros elementos del stack b
void sb(t_stack *b)
{
    sa(b);
}

// sa and sb a la vez
void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

void pa(t_stack* a, t_stack* b)
{
    if (b->top == NULL) {
        return; // Stack b is empty
    }
    int data = pop(b);
    push(a, data);
}


void pb(t_stack* a, t_stack* b)
{
    if (a->top == NULL) {
        return; // Stack a is empty
    }
    int data = pop(a);
    push(b, data);

}

//Desplaza hacia a arriba todos los elementos del stack y el primero pasa a ser el ultimo
void ra(t_stack *a){

    if (a == NULL || a->top == NULL || a->top->next == NULL) {
        return;
    }
    t_node *temp = a->top;
    a->top = a->top->next;
    t_node *current = a->top;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
    temp->next = NULL;
}

void rb(t_stack *b)
{

    if (b == NULL || b->top == NULL || b->top->next == NULL) {
        return;
    }
    t_node *temp = b->top;
    b->top = b->top->next;
    t_node *current = b->top;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
    temp->next = NULL;
}

void rr(t_stack *a, t_stack *b)
{
    if (a->top == NULL || b->top == NULL)
        return;
    ra(a);
    rb(b);
}
void rra(t_stack *a)
{
    if (a->top == NULL || a->top->next == NULL) {
        return;  // No hay nada que rotar
    }

    // Encontrar el penúltimo nodo
    t_node* second_to_last = a->top;
    while (second_to_last->next->next != NULL) {
        second_to_last = second_to_last->next;
    }

    // El último nodo se convierte en el nuevo top
    t_node* last = second_to_last->next;
    second_to_last->next = NULL;  // Desconectar el último nodo
    last->next = a->top;
    a->top = last;
}

void rrb(t_stack *b)
{
    if (b->top == NULL || b->top->next == NULL) {
        return;  // No hay nada que rotar
    }

    // Encontrar el penúltimo nodo
    t_node* second_to_last = b->top;
    while (second_to_last->next->next != NULL) {
        second_to_last = second_to_last->next;
    }

    // El último nodo se convierte en el nuevo top
    t_node* last = second_to_last->next;
    second_to_last->next = NULL;  // Desconectar el último nodo
    last->next = b->top;
    b->top = last;
}

void rrr(t_stack *a, t_stack *b)
{
    if (a->top == NULL || b->top == NULL)
        return;
    rra(a);
    rrb(b);
}