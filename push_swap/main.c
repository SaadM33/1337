/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:48:21 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/27 23:43:23 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		handle_input(argv, &stack_a);
		if (!is_sorted(stack_a))
		{
			if (get_stack_size(stack_a) == 2)
				do_op("sa", &stack_a, &stack_b);
			else if (get_stack_size(stack_a) == 3)
				tiny_sort(&stack_a, &stack_b);
			else if (get_stack_size(stack_a) > 3)
				sort_turk(&stack_a, &stack_b);
		}
	}
	free_stack(&stack_a);
	return (0);
}
