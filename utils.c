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