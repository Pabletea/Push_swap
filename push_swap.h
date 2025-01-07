/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:30:21 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/03 14:56:57 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/*------------------------DEFINICIONES------------------------*/
typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_stack;
/*------------------------INSTRUCTIONS------------------------*/

int					swap(t_stack **stack);
int	sa(t_stack **stack_a/*,t_stack **stack_b*/);
int	sb(/*t_stack **stack_a,*/t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

int					push(t_stack **stack_orig, t_stack **stack_dest);

int					pa(t_stack **stack_a, t_stack **stack_b);

int					pb(t_stack **stack_a, t_stack **stack_b);

int					rotate(t_stack **stack);

int					ra(t_stack **stack_a/*, t_stack **stack_b*/);
int					rb(/*t_stack **stack_a,*/ t_stack **stack_b);

int					rr(t_stack **stack_a, t_stack **stack_b);

int					reverseRotate(t_stack **stack);

int	rra(t_stack **stack_a/*,t_stack **stack_b*/);

int					rrb(/*t_stack **stack_a, */t_stack **stack_b);

int					rrr(t_stack **stack_a, t_stack **stack_b);

/*------------------------UTILS------------------------*/

int					stack_len(t_stack **stack);
void				initializeStack(t_stack **stack, int *stackValues,
						int nValues);
void				imprimir_estado(t_stack **a, t_stack **b);
int					isSorted(t_stack **stack);
int getHighestNode(t_stack **stack);
int					getLowestNode(t_stack **stack);
void				sortStack(t_stack **stack_a, t_stack **stack_b);
int getRange(t_stack **stack, int value);
void free_stack(t_stack *stack);

/*------------------------STACK UTILS-------------------*/

int closest_number(t_stack **stack, int min, int max);

/*------------------------LIST UTILS--------------------*/

t_stack				*getLast(t_stack *top);

/*------------------------ALGORITHM-------------------*/

void sort_three(t_stack **stack_a/*,t_stack **stack_b*/);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void sortAlgorithm(t_stack **stack_a, t_stack **stack_b);
#endif