#include "push_swap.h"

int stack_len(t_stack stack)
{
    int count = 0;
    t_node *current = stack.top;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}


int fillStack(t_stack *stack, int *stackValues, int nValues)
{
    int i;

    if (!stack|| !stackValues)
        return (-1);
    i = 0;

    int j = 0;
    printf("Elementos del array del que rellena el stack : !!");
    while(stackValues[j])
    {

        printf("%d",stackValues[j]);
        j++;
    }

    while(i < nValues)
    {
        t_node *newNode = (t_node *)malloc(sizeof(t_node));
        if (!newNode)
            return (-1);
        newNode->data = stackValues[i];
        newNode->next = stack->top;
        stack->top = newNode;
        i++;

    }
    return (1);
}
void initializeStack(t_stack *stack, int nValues)
{
    // Inicializa la pila
    stack->top = NULL;

    int i = 0;
    while (i < nValues)
    {
        t_node *newNode = (t_node *)malloc(sizeof(t_node));
        if (!newNode)
        {
            // En caso de error, libera todos los nodos ya reservados
            while (stack->top)
            {
                t_node *temp = stack->top;
                stack->top = stack->top->next;
                free(temp);
            }
            return; // Finaliza la función si hay un error
        }

        // Conecta el nuevo nodo a la pila
        newNode->data = 0; // Opcional: puedes inicializar con un valor neutro si es necesario
        newNode->next = stack->top;
        stack->top = newNode;

        i++;
    }
}