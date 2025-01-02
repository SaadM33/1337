#include "push_swap.h"

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


