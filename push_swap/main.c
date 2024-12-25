/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:48:21 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/24 21:48:24 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc >= 2)
	{
		handle_input(argv, argc, &stack_a);
		
	}
	free_stack(&stack_a);
	return (0);
}

void handle_input(char **av, int ac, t_stack **stack_a)
{
    int     i;
    char    **args;

    i = 0;
    if (ac == 2)
        args = ft_split(av[1], ' ');
    else
        args = &av[1];
    while (args[i])
    {
        if (!is_valid_number(args[i]))
			handle_error(stack_a, args, ac);
		else if (!check_duplicate(*stack_a, ft_atol(args[i])))
			handle_error(stack_a, args, ac);
		add_to_stack(stack_a, ft_atol(args[i]), args, ac);
        i++;
    }
    if (ac == 2)
        free_split(args);
}

void add_to_stack(t_stack **stack, int value, char **args, int ac)
{
    t_stack *new_node;
    t_stack *temp;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        handle_error(stack, args, ac);
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

void handle_error(t_stack **stack_a, char **args, int ac)
{
    free_stack(stack_a);
	if (ac == 2)
		free_split(args);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}
