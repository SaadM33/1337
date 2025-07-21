/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:36:26 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:16 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_files(t_cmd *cmd, t_token *curr, t_data *data, char *filename)
{
	if (!ft_strcmp(curr->arg, ">") || !ft_strcmp(curr->arg, ">>"))
	{
		if (open_out_files(cmd, curr, data, filename) == -1)
			return (-1);
	}
	if (!ft_strcmp(curr->arg, "<"))
	{
		if (open_in_files(cmd, data, curr, filename) == -1)
			return (-1);
	}
	return (0);
}

void	free_appended_nodes(t_token **head, t_token *node)
{
	t_token	*tmp;

	if (node->type == 3)
	{
		tmp = node->next;
		remove_token(head, node);
		node = tmp;
	}
	tmp = node;
	while (tmp && tmp->next && tmp->append)
	{
		node = tmp;
		tmp = tmp->next;
		remove_token(head, node);
	}
	remove_token(head, tmp);
}

void	ambiguous_error(t_token *node)
{
	char *(s), *str1, *str2;
	s = ft_strdup("");
	while (node && node->type < OP)
	{
		if (node->type == DQ)
		{
			str1 = ft_strjoin3(s, "\"", node->arg);
			str2 = ft_strjoin(str1, "\"");
			ft_free(str1);
		}
		else if (node->type == SQ)
		{
			str1 = ft_strjoin3(s, "'", node->arg);
			str2 = ft_strjoin(str1, "'");
			ft_free(str1);
		}
		else
			str2 = ft_strjoin(s, node->arg);
		ft_free(s);
		s = str2;
		if (!node->append)
			break ;
		node = node->next;
	}
	return (ft_error3("minishell: ", s, ": ambiguous redirect\n"), ft_free(s));
}

int	redirect(t_token *curr, t_cmd *cmd, t_data *data)
{
	t_token	*tmp;

	if (cmd->in_fd != -1 && cmd->out_fd != -1
		&& curr->type == OP && ft_strcmp(curr->arg, "<<"))
	{
		tmp = ft_expand_and_join(curr->next, data, 0, NULL);
		if (!tmp || !tmp->arg || tmp->next)
		{
			ambiguous_error(curr->next);
			if (!ft_strcmp(curr->arg, "<"))
				cmd->in_fd = -1;
			free_token_list(&tmp);
			return (data->exit_code = 1, cmd->skip_cmd = 1, 1);
		}
		if (open_files(cmd, curr, data, tmp->arg))
		{
			ft_error4("minishell: ", tmp->arg, ": ", strerror(errno));
			return (ft_error("\n"), free_token_list(&tmp),
				data->exit_code = 1, cmd->skip_cmd = 1, 1);
		}
		free_token_list(&tmp);
	}
	return (0);
}

int	handle_redirections(t_data *data, t_cmd *cmd)
{
	t_token	*curr;

	while (cmd)
	{
		curr = cmd->list;
		while (curr)
		{
			if (cmd->out_fd != -1 || cmd->in_fd != -1)
				redirect(curr, cmd, data);
			if (curr->type == OP)
			{
				free_appended_nodes(&cmd->list, curr);
				curr = cmd->list;
			}
			else
				curr = curr->next;
		}
		cmd = cmd->next;
	}
	return (1);
}
