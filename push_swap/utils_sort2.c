/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:13:57 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/06 00:00:49 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_save_three(t_stack **a, t_stack **b)
{
	int len_a;

	len_a = get_stack_size(*a);
	while (len_a-- > 3)
		do_op("pb", a, b);
}

t_stack	*find_smallest(t_stack *a)
{
    t_stack *smallest;

	smallest = a;
    while (a)
	{
        if (a->value < smallest->value)
		{
            smallest = a;
        }
        a = a->next;
    }
    return smallest;
}

void calculate_cost(t_stack *stack, t_stack *node)
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
	if (position >= size / 2)
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

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
