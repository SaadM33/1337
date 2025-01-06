/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:35 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/04 22:14:35 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
#include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		value;
	int		cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void	handle_input(char **av, t_stack **stack_a);
int		is_valid_number(char *str);
void	add_to_stack(t_stack **stack, int value, char **args);
void 	handle_error(t_stack **stack_a, char **args);
void	free_split(char **args);
void 	free_stack(t_stack **stack);
long	ft_atol(const char *str);
int 	check_duplicate(t_stack *stack, int value);
int		ft_abs(int n);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rot_a(t_stack **stack_a);
void	rot_b(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	revrot_a(t_stack **stack_a);
void	revrot_b(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack *stack_a);
void 	sort_turk(t_stack **stack_a, t_stack **stack_b);
int		get_stack_size(t_stack *lst);
void	do_op(char *op, t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack_a, t_stack **stack_b);

void	push_all_save_three(t_stack **a, t_stack **b);
t_stack	*find_smallest(t_stack *a);
void	calculate_cost(t_stack *stack, t_stack *node);
void	fill_costs(t_stack *a, t_stack *b);
void	find_targets(t_stack *a, t_stack *b);
void	shift_stack(t_stack **a, t_stack **b);
void	move_cheapest(t_stack **a, t_stack **b);
t_stack *find_cheapest_move(t_stack *b);
int		find_median(t_stack *stack);
void	sort_array(int *arr, int size);
#endif
