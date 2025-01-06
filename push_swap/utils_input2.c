/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:54:21 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/06 17:54:33 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_input(char **av, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**args;

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

void	add_to_stack(t_stack **stack, int value, char **args)
{
	t_stack	*new_node;
	t_stack	*temp;

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

void	handle_error(t_stack **stack_a, char **args)
{
	free_stack(stack_a);
	free_split(args);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}