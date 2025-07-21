/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:43:02 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:11:01 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_node(t_token **head, char *arg, int type, int append)
{
	t_token	*new;
	t_token	*curr;

	new = ft_malloc(sizeof(t_token));
	new->arg = arg;
	new->type = type;
	new->append = append;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

void	remove_token(t_token **head, t_token *node)
{
	t_token	*tmp;

	if (!node || !head || !*head)
		return ;
	if (*head == node)
	{
		*head = node->next;
		ft_free(node->arg);
		ft_free(node);
	}
	else
	{
		tmp = *head;
		while (tmp->next && tmp->next != node)
			tmp = tmp->next;
		if (tmp->next)
			tmp->next = tmp->next->next;
		ft_free(node->arg);
		ft_free(node);
	}
}

void	free_token_list(t_token **head)
{
	t_token	*current;
	t_token	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		ft_free(current->arg);
		ft_free(current);
		current = next;
	}
	*head = NULL;
}

void	print_token_list(t_token *lst)
{
	while (lst)
	{
		printf("str: %s	type: %i  append: %i\n", lst->arg,
			lst->type, lst->append);
		lst = lst->next;
	}
}
