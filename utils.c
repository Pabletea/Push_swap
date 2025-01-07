#include "push_swap.h"

int stack_len(t_stack **stack)
{
    int count = 0;
    t_stack *current = *stack;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

void initializeStack(t_stack **stack, int *stackValues, int nValues)
{
    if (!stack || !stackValues || nValues <= 0)
        return;
    *stack = NULL; // Inicializa la pila
    int i = 0;
    while (i < nValues)
    {
        t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
        if (!newNode)
        {
            while (*stack) // En caso de error, libera todos los nodos ya reservados
            {
                t_stack *temp = *stack;
                *stack = (*stack)->next;
                free(temp);
            }
            return;
        }
        newNode->data = stackValues[i]; // Inicializar el nuevo nodo
        newNode->index = i; // Opcional: asignar un índice
        newNode->next = *stack;
        *stack = newNode; // Actualizar la cima de la pila
        i++;
    }
}

int isSorted(t_stack **stack)
{
    t_stack *current = *stack;

    while (current && current->next)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }
    return (1);
}



int getLowestNode(t_stack **stack) {
    if (*stack == NULL) 
        return INT_MAX;
    t_stack *current = *stack;
    int minimum = current->data;

    while (current != NULL) {
        if (current->data < minimum) {
            minimum = current->data;
        }
        current = current->next;
    }

    return minimum;
}

int getHighestNode(t_stack **stack) {
    if (*stack == NULL) 
        return INT_MAX;
    t_stack *current = *stack;
    int maximun = current->data;

    while (current != NULL) {
        if (current->data > maximun) {
            maximun = current->data;
        }
        current = current->next;
    }

    return maximun;
}

int getRange(t_stack **stack, int value) {
    if (*stack == NULL) {
        // Handle empty stack case
        return -1; // Or any appropriate value to indicate error
    }

    t_stack *current = *stack;
    int range = 0; 

    while (current != NULL) {
        if (current->data == value) {
            return range; 
        }
        range++;
        current = current->next;
    }

    // If the loop completes without finding the value
    return -1; // Or any appropriate value to indicate value not found
}

void free_stack(t_stack *stack)
{
    t_stack *temp;
    while(stack){
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}



