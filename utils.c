#include "push_swap.h"

int stack_len(t_stack *stack)
{
    int count = 0;
    t_node *current = stack->top;
    
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
void initializeStack(t_stack *stack, int *stackValues, int nValues)
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
        newNode->data = stackValues[i]; // Opcional: puedes inicializar con un valor neutro si es necesario
        newNode->next = stack->top;
        stack->top = newNode;

        i++;
    }
    
}

void push(t_stack* stack, int data) {
    t_node* newNode = (t_node*)malloc(sizeof(t_node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(t_stack* stack) {
    if (stack->top == NULL) {
        // Pila vacía
        return -1;
    }
    t_node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

