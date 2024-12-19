/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:30:21 by pabalons          #+#    #+#             */
/*   Updated: 2024/12/03 10:29:34 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
/*------------------------DEFINICIONES------------------------*/
typedef struct t_node
{
	int				data;
	int 			index;
	struct t_node	*target;
	struct t_node	*next;
	struct t_node   *prev;
}					t_node;

// Definimos el stack
typedef struct t_stack
{
	t_node			*top;
}					t_stack;

/*------------------------INSTRUCTIONS------------------------*/

void 				sa(t_stack *a);

void				sb(t_stack *b);

void				ss(t_stack *a, t_stack *b);

void				pa(t_stack* a, t_stack* b);

void				pb(t_stack* a, t_stack* b);

void				ra(t_stack *a);

void				rb(t_stack *b);

void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);

void				rrb(t_stack *b);

void				rrr(t_stack *a, t_stack *b);

/*------------------------UTILS------------------------*/

int					stack_len(t_stack *stack);
int fillStack(t_stack *stack, int *stackValues, int nValues);
void initializeStack(t_stack *stack, int nValues);
void push(t_stack* stack, int data);
int pop(t_stack* stack);

/*------------------------STACK UTILS-------------------*/

t_node *findMax(t_stack *a);

/*------------------------ALGORITHM-------------------*/

void sort_three(t_stack *a);
#endif