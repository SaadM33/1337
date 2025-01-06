/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RevRotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:53:40 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/25 09:56:57 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;	
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	revrot_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;	
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	revrot_a(stack_a);
	revrot_b(stack_b);
}