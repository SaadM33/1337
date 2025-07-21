/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:52:56 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:58 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd_node(t_cmd **head, t_token *list)
{
	t_cmd	*new;
	t_cmd	*curr;

	new = ft_malloc(sizeof(t_cmd));
	new->list = list;
	new->in_fd = 0;
	new->out_fd = 1;
	new->skip_cmd = 0;
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

void	free_cmd_list(t_cmd **head)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free_token_list(&current->list);
		if (current->in_fd > 2)
			close(current->in_fd);
		if (current->out_fd > 2)
			close(current->out_fd);
		ft_free(current);
		current = next;
	}
	*head = NULL;
}

void	print_cmd_list(t_cmd *head)
{
	t_cmd	*curr;
	t_token	*token;

	curr = head;
	while (curr)
	{
		printf("Command:\n");
		token = curr->list;
		while (token)
		{
			printf("  Arg: %s, Type: %d\n", token->arg, token->type);
			token = token->next;
		}
		printf("In-fd: %d, Out-fd: %d, Skip: %d\n",
			curr->in_fd, curr->out_fd, curr->skip_cmd);
		curr = curr->next;
	}
}

void	list_to_cmds(t_data *data)
{
	t_token	*current;
	t_token	*tmp_list;

	current = data->token_list;
	tmp_list = NULL;
	while (current)
	{
		while (current && current->type != PP)
		{
			add_token_node(&tmp_list, ft_strdup(current->arg),
				current->type, current->append);
			current = current->next;
		}
		add_cmd_node(&data->cmd_list, tmp_list);
		tmp_list = NULL;
		if (current && current->type == PP)
			current = current->next;
	}
}
