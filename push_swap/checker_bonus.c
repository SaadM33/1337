/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:25:58 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/06 21:09:21 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"


void	execute_inst(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap_a(stack_a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap_b(stack_b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push_b(stack_a, stack_b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rot_a(stack_a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rot_b(stack_b);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		revrot_a(stack_a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		revrot_b(stack_b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rrr(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char *line;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		handle_input(argv, &a);
		line = get_next_line(0);
		while(line)
		{
			line = get_next_line(0);
			execute_inst(line, &a, &b);
		}
		ft_putstr_fd("OK\n", 1);
	}
	free_stack(&a);
	return (0);
}
