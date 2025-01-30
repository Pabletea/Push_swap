#include "push_swap.h"

t_stack	*findMax(t_stack **a)
{
	long	max;
	t_stack	*max_node;
	t_stack	*current;

	current = *a;
	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (current != NULL)
	{
		if (current->data > max)
		{
			max = current->data;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

t_stack	*getLast(t_stack *top)
{
	t_stack	*tmp;

	tmp = top;
	while (top->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}