
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
	if (position > size / 2)
        node->cost = size - position;
    else
		node->cost = position; 
}

t_stack	*find_cheapest_move(t_stack *b, int *min_cost,
		t_stack **cheapest_b, t_stack **cheapest_a)
{
	t_stack	*cur_b;

	cur_b = b;
	while (cur_b)
	{
		t_stack	*cur_a = cur_b->target;
		
		if (cur_a)
		{
			int total_cost;

			total_cost = cur_a->cost + cur_b->cost;
			if (total_cost < *min_cost)
			{
				*min_cost = total_cost;
				*cheapest_b = cur_b;
				*cheapest_a = cur_a;
			}
		}
		cur_b = cur_b->next;
	}
	return (*cheapest_b);
}

void	execute_move(t_stack **a, t_stack **b, t_stack *cheapest_b,
		t_stack *cheapest_a)
{
	int rr_moves;

	if (cheapest_b->cost < cheapest_a->cost)
		rr_moves = cheapest_b->cost;
	else
		rr_moves = cheapest_a->cost;

	for (int i = 0; i < rr_moves; i++)
		do_op("rr", a, b);

	cheapest_b->cost -= rr_moves;
	cheapest_a->cost -= rr_moves;

	while (cheapest_b->cost > 0)
	{
		do_op("rb", a, b);
		cheapest_b->cost--;
	}
	while (cheapest_a->cost > 0)
	{
		do_op("ra", a, b);
		cheapest_a->cost--;
	}
	while (cheapest_b->cost < 0)
	{
		do_op("rrb", a, b);
		cheapest_b->cost++;
	}
	while (cheapest_a->cost < 0)
	{
		do_op("rra", a, b);
		cheapest_a->cost++;
	}
	push_node_to_stack_a(a, b, cheapest_b);
}
