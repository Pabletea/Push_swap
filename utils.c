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
    {}
    else if (stackNodes > 5)
    {}
}

int getLowestNode(t_stack **stack)
{
    t_stack *current = *stack;
    int minimun = 0;
    while(current->next)
    {
        if(current->data < current->next->data)
            minimun = current->data;
        current = current->next;
    }
    return (minimun);
}



