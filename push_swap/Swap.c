/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:34:22 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/25 09:45:50 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*head;
 	t_stack	*next;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	head = *stack_a;
	next = *stack_a;
	*stack_a = next;
	head->next = next->next;
	next->next = head;
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*head;
 	t_stack	*next;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return;
	head = *stack_b;
	next = *stack_b;
	*stack_b = next;
	head->next = next->next;
	next->next = head;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}