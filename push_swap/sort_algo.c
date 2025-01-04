

#include "push_swap.h"

void	sort_turk(t_stack **a, t_stack **b)
{
	push_all_save_three(a, b);
	tiny_sort(a, b);
	while (*b)
	{
		find_targets(*a, *b);
		fill_costs(*a, *b);
		move_cheapest(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}

void	tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		biggest;
	int		value;

	tmp = *stack_a;
	value = tmp->value;
	while (tmp)
	{
		if (value <= tmp->value)
			value = tmp->value;
		tmp = tmp->next;
	}
	biggest = value;
	if ((*stack_a)->value == biggest)
		do_op("ra", stack_a, stack_b);
	else if ((*stack_a)->next->value == biggest)
		do_op("rra", stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		do_op("sa", stack_a, stack_b);
}


void	find_targets(t_stack *a, t_stack *b)
{
	int closest_max;
	t_stack *current_a;

	while (b)
	{
		closest_max = INT_MAX;
		current_a = a;
		b->target = NULL;
		while (current_a)
		{
			if (b->value < current_a->value && current_a->value < closest_max)
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


void fill_costs(t_stack *a, t_stack *b)
{
    t_stack *cur_a;
    t_stack *cur_b;

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

void	move_cheapest(t_stack **a, t_stack **b)
{
	int		min_cost;
	t_stack	*cheapest_b;
	t_stack	*cheapest_a;

	min_cost = INT_MAX;
	cheapest_b = NULL;
	cheapest_a = NULL;
	find_cheapest_move(*b, &min_cost, &cheapest_b, &cheapest_a);
	if (cheapest_b && cheapest_a)
		execute_move(a, b, cheapest_b, cheapest_a);
}



