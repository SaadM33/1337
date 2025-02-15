/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:33:48 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/07 17:02:46 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_stack *stack_a)
{
	int	s_size;

	s_size = get_stack_size(stack_a);
	while (s_size >= 2 && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	shift_stack(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		cost;

	if (is_sorted(*a))
		return ;
	smallest = find_smallest(*a);
	calculate_cost(*a, smallest);
	cost = smallest->cost;
	if (cost > 0)
		while (cost-- > 0)
			do_op("ra", a, b);
	else
		while (cost++ < 0)
			do_op("rra", a, b);
}

void	do_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(op, "rra") == 0)
		revrot_a(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		revrot_b(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(stack_a, stack_b);
	if (ft_strcmp(op, "sa") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(op, "ra") == 0)
		rot_a(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rot_b(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(stack_a, stack_b);
	ft_putendl_fd(op, 1);
}

int	get_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
