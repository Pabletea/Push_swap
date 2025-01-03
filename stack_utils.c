#include "push_swap.h"


t_stack *findMax(t_stack **a)
{
    long    max;
    t_stack *max_node;
    t_stack *current = *a;

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

t_stack *getLast(t_stack *top)
{
    t_stack *tmp;

    tmp = top;
    while (top->next)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
            return(tmp);
    }
    return(tmp);


}

int closest_number(t_stack **stack, int min, int max) {
    t_stack *current = *stack;
    int best_distance = -1;
    int closest = -1;
    while (current) {
        if (current->data >= min && current->data <= max) {
            int distance = current->index < stack_len(stack) / 2 ? current->index : stack_len(stack) - current->index;
            if (best_distance == -1 || distance < best_distance) {
                best_distance = distance;
                closest = current->data;
            }
        }
        current = current->next;
    }
    return closest;
}