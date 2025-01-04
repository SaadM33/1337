/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:33:48 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/04 00:09:11 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int s_size;

	s_size = get_stack_size(stack_a);
	while( s_size >= 2 && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void shift_stack(t_stack **a)
{
    if (!is_sorted(*a)) {
        while (!is_sorted(*a)) {
            rotate_stack(a, NULL, "ra");
        }
    }
}


void	do_op(char *op, t_stack **stack_a, t_stack **stack_b)
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
	else if (ft_strncmp(op, "rra", 2) == 0)
		revrot_a(stack_a);
	else if (ft_strncmp(op, "rrb", 2) == 0)
		revrot_b(stack_b);
	else if (ft_strncmp(op, "rrr", 2) == 0)
		rrr(stack_a, stack_b);
	ft_putendl_fd(op, 1);
}

int	get_stack_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
