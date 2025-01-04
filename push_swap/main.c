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
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
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
		t_stack *temp = stack_a;
		printf("\n\n");
		while (temp)
		{
			printf("%d\n", temp->value);
			temp = temp->next;
		}
	}
	free_stack(&stack_a);
	return (0);
}

void handle_input(char **av, t_stack **stack_a)
{
	int i;
	int	j;
	char **args;

	i = 1;
	while (av[i])
	{
		args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
	    {
			if (!is_valid_number(args[j]))
				handle_error(stack_a, args);
			if (!check_duplicate(*stack_a, ft_atol(args[j])))
				handle_error(stack_a, args);
			add_to_stack(stack_a, ft_atol(args[j]), args);
	        j++;
	    }
		free_split(args);
		i++;
	}
}

void add_to_stack(t_stack **stack, int value, char **args)
{
	t_stack *new_node;
	t_stack *temp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error(stack, args);
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void handle_error(t_stack **stack_a, char **args)
{
	free_stack(stack_a);
	free_split(args);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

