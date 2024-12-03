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
