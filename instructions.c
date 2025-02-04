/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:06:07 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 17:28:50 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}		

void	ra(t_stack **a) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	rotate(a);
	ft_printf(1,"ra\n");
}

void	rb(t_stack **b) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	ft_printf(1,"rb\n");
}

void	rr(t_stack **a, t_stack **b) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	rotate(a);
	rotate(b);
	ft_printf(1,"rr\n");
}

static void swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!head || !*head || !(*head)->next)
        return;

    first = *head;
    second = first->next;
    third = second->next; // could be NULL

    // Swap first and second:
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;

    // Update head:
    *head = second;
}

void	sa(t_stack	**a) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	ft_printf(1,"sa\n");
}

void	sb(t_stack **b) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	ft_printf(1,"sb\n");
}

void	ss(t_stack **a, t_stack **b) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	ft_printf(1,"ss\n");
}
static void	push(t_stack **dst, t_stack **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_stack` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_stack **a, t_stack **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	ft_printf(1,"pa\n");
}

void	pb(t_stack **b, t_stack **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	ft_printf(1,"pb\n");
}

static void rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (stack_len(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;              // Update head pointer to the last node
}


void rra(t_stack **a)
{
    rev_rotate(a);
	ft_printf(1,"rra\n");
}
void	rrb(t_stack **b) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	ft_printf(1,"rrb\n");
}

void	rrr(t_stack **a, t_stack **b) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf(1,"rrr\n");
}

void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}