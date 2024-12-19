#include "push_swap.h"


t_node *findMax(t_stack *a)
{
    long    max;
    t_node *max_node;
    t_node *current = a->top;

    if (!a)
        return (NULL);
    max = LONG_MIN;
    while(current != NULL)
    {
        if(current->data > max)
        {
            max = current->data;
            max_node = current;
        }
        current = current->next;
    }
    return(max_node);
}