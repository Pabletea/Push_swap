/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:30:21 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/04 21:50:18 by pabalons         ###   ########.fr       */
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

typedef struct s_list
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	int				is_cheapiest;
	struct s_list	*next;
	struct s_list	*target_node;
	struct s_list	*prev;
}					t_stack;

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);

void				pb(t_stack **b, t_stack **a);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);

void				rrb(t_stack **b);

void				rrr(t_stack **a, t_stack **b);

int					stack_len(t_stack *stack);
void				initializeStack(t_stack **stack, int *stackValues,
						int nValues);
void				imprimir_estado(t_stack **a, t_stack **b);
int					isSorted(t_stack *stack);
int					getHighestNode(t_stack **stack);
int					getLowestNode(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					getRange(t_stack **stack, int value);
void				free_stack(t_stack *stack);
void				imprimir_node(t_stack *node);
t_stack				*find_min(t_stack *stack);

void				current_index(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);
t_stack				*find_max(t_stack *stack);

void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);

t_stack				*find_last(t_stack *stack);
t_stack				*ft_lstlast(t_stack *head);

void				sort_three(t_stack **a);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_stacks(t_stack **a, t_stack **b);

void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);

void				rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);

#endif