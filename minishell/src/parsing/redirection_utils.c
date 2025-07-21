/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:34:41 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:11 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_prev_fd(t_cmd *cmd, int in_or_out)
{
	if (in_or_out == 0 && cmd->in_fd != 0 && cmd->in_fd != -1)
		close(cmd->in_fd);
	else if (in_or_out == 1 && cmd->out_fd != 1 && cmd->out_fd != -1)
		close(cmd->out_fd);
}

int	open_in_files(t_cmd *cmd, t_data *data, t_token *curr, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close_prev_fd(cmd, 0);
		close_prev_fd(cmd, 1);
		data->exit_code = 1;
		cmd->skip_cmd = 1;
		cmd->in_fd = -1;
		return (-1);
	}
	if (cmd->in_fd == 0 && last_in_redirection(cmd, curr->next))
	{
		close_prev_fd(cmd, 0);
		cmd->in_fd = fd;
	}
	else
		close(fd);
	return (0);
}

int	open_out_files(t_cmd *cmd, t_token *curr, t_data *data, char *filename)
{
	int	fd;

	close_prev_fd(cmd, 1);
	if (!ft_strcmp(curr->arg, ">"))
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		close_prev_fd(cmd, 0);
		data->exit_code = 1;
		cmd->skip_cmd = 1;
		cmd->out_fd = -1;
		return (-1);
	}
	cmd->out_fd = fd;
	return (0);
}

int	last_in_redirection(t_cmd *cmd, t_token *node)
{
	t_token	*tmp;
	t_token	*tmp1;
	int		has_in_red_after;

	tmp = cmd->list;
	while (tmp)
	{
		has_in_red_after = 0;
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (!ft_strcmp(tmp1->arg, "<") || !ft_strcmp(tmp1->arg, "<<"))
			{
				has_in_red_after = 1;
				break ;
			}
			tmp1 = tmp1->next;
		}
		if (tmp->type == OP && (!ft_strcmp(tmp->arg, "<<") || !ft_strcmp(
					tmp->arg, "<")) && tmp->next == node && has_in_red_after)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_should_expand(t_token *node)
{
	int	should_expand;

	should_expand = 1;
	while (node && node->append && node->next)
	{
		if (node->type)
			should_expand = 0;
		node = node->next;
	}
	if (node->type)
		should_expand = 0;
	return (should_expand);
}
