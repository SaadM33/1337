/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:13:50 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/04 22:13:50 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_turk(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	push_all_save_three(a, b);
	tiny_sort(a, b);
	while (*b)
	{
		find_targets(*a, *b);
		fill_costs(*a, *b);
		cheapest = find_cheapest_move(*b);
		move_cheapest(a, b, cheapest);
	}
	if (!is_sorted(*a))
		shift_stack(a, b);
}

void	tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;
	t_stack	*mid;
	t_stack	*bot;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	top = *stack_a;
	mid = top->next;
	bot = mid->next;
	if (top->value > mid->value && top->value > bot->value)
		do_op("ra", stack_a, stack_b);
	else if (mid->value > top->value && mid->value > bot->value)
		do_op("rra", stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		do_op("sa", stack_a, stack_b);
}

void	find_targets(t_stack *a, t_stack *b)
{
	int		closest_max;
	t_stack	*current_a;

	while (b)
	{
		closest_max = INT_MAX;
		current_a = a;
		b->target = NULL;
		while (current_a)
		{
			if (b->value < current_a->value
				&& current_a->value < closest_max)
			{
				b->target = current_a;
				closest_max = current_a->value;
			}
			current_a = current_a->next;
		}
		if (!b->target)
		{
			b->target = find_smallest(a);
		}
		b = b->next;
	}
}

void	fill_costs(t_stack *a, t_stack *b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = a;
	cur_b = b;
	while (cur_a)
	{
		calculate_cost(a, cur_a);
		cur_a = cur_a->next;
	}
	while (cur_b)
	{
		calculate_cost(b, cur_b);
		cur_b = cur_b->next;
	}
}

void	move_cheapest(t_stack **a, t_stack **b, t_stack	*cheapest)
{
	int		cost_a;
	int		cost_b;

	cost_b = cheapest->cost;
	cost_a = cheapest->target->cost;
	while (cost_a > 0 && cost_b > 0 && cost_a-- && cost_b--)
		do_op("rr", a, b);
	while (cost_a < 0 && cost_b < 0 && cost_a++ && cost_b++)
		do_op("rrr", a, b);
	while (cost_a > 0 && cost_a--)
		do_op("ra", a, b);
	while (cost_a < 0 && cost_a++)
		do_op("rra", a, b);
	while (cost_b > 0 && cost_b--)
		do_op("rb", a, b);
	while (cost_b < 0 && cost_b++)
		do_op("rrb", a, b);
	do_op("pa", a, b);
}
