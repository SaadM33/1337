/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:13:57 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/14 21:39:46 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a)
	{
		if (a->value < smallest->value)
		{
			smallest = a;
		}
		a = a->next;
	}
	return (smallest);
}

void	calculate_cost(t_stack *stack, t_stack *node)
{
	int	position;
	int	size;

	position = 0;
	size = get_stack_size(stack);
	while (stack && stack != node)
	{
		position++;
		stack = stack->next;
	}
	if (position > size / 2)
		node->cost = position - size;
	else
		node->cost = position;
}

t_stack	*find_cheapest_move(t_stack *b)
{
	t_stack	*cur_b;
	t_stack	*cheapest;
	int		total_cost;
	int		min_cost;

	cur_b = b;
	min_cost = INT_MAX;
	while (cur_b)
	{
		total_cost = ft_abs(cur_b->cost) + ft_abs(cur_b->target->cost);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = cur_b;
		}
		cur_b = cur_b->next;
	}
	return (cheapest);
}

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	mid_value;

	stack_size = get_stack_size(*stack_a);
	mid_value = find_median(*stack_a);
	pushed = 0;
	while (stack_size > 3 && pushed < stack_size / 2)
	{
		if ((*stack_a)->value <= mid_value)
		{
			do_op("pb", stack_a, stack_b);
			pushed++;
		}
		else
			do_op("ra", stack_a, stack_b);
	}
	while (stack_size - pushed > 3)
	{
		do_op("pb", stack_a, stack_b);
		pushed++;
	}
}

int	find_median(t_stack *stack)
{
	int		*values;
	int		size;
	int		i;
	t_stack	*tmp;
	int		median;

	size = get_stack_size(stack);
	values = malloc(size * sizeof(int));
	if (!values)
		exit(1);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		values[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}
