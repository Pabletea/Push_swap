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


// int fillStack(t_stack *stack, int *stackValues, int nValues)
// {
//     int i;

//     if (!stack|| !stackValues)
//         return (-1);
//     i = 0;


//     while(i < nValues)
//     {
//         t_node *newNode = (t_node *)malloc(sizeof(t_node));
//         if (!newNode)
//             return (-1);
//         newNode->data = stackValues[i];
//         newNode->next = stack->top;
//         stack->top = newNode;
//         i++;

//     }
//     return (1);
// }
void initializeStack(t_stack **stack, int *stackValues, int nValues)
{

    if (!stack || !stackValues || nValues <= 0)
        return;

    // Inicializa la pila
    *stack = NULL;

    int i = 0;
    while (i < nValues)
    {
        t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
        if (!newNode)
        {
            // En caso de error, libera todos los nodos ya reservados
            while (*stack)
            {
                t_stack *temp = *stack;
                *stack = (*stack)->next;
                free(temp);
            }
            return; // Finaliza la función si hay un error
        }
        // Inicializar el nuevo nodo
        newNode->data = stackValues[i];
        newNode->index = i; // Opcional: asignar un índice
        newNode->next = *stack;

        // Actualizar la cima de la pila
        *stack = newNode;

        i++;
    }
    
}



