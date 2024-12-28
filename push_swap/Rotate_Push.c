/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate_Push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:05:48 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/24 22:27:38 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_b || !(*stack_b))
		return; 
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = *stack_b;
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !(*stack_a))
		return; 
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = *stack_b;
	*stack_a = *stack_a;
}

void    rot_a(t_stack **stack_a)
{
	t_stack *head;
	t_stack *temp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	head = *stack_a;
	*stack_a = head->next;
	head->next = NULL;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
}

void    rot_b(t_stack **stack_b)
{
	t_stack *head;
	t_stack *temp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return;
	head = *stack_b;
	*stack_b = head->next;
	head->next = NULL;
	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
	rot_a(stack_a);
	rot_b(stack_b);
}