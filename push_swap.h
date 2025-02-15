/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:30:21 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/06 12:33:15 by pabalons         ###   ########.fr       */
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
void				initialize_stack(t_stack **stack, int *stackValues,
						int nValues);
void				imprimir_estado(t_stack **a, t_stack **b);
int					is_sorted(t_stack *stack);
int					get_highest_node(t_stack **stack);
int					get_lowest_node(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					get_range(t_stack **stack, int value);
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
char				*arguments_union(char **argv);
int					is_valid_number(char *str);
int					check_arguments(char **argv);
void				free_all_memory(char *argv_union, char **arr_arguments);
int					check_duplicates(int *stack_values, int len);
void				print_array(int *stack_values);
void				free_arguments(char **args);
#endif