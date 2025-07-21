/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:33:00 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:18 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_data *data, t_cmd *cmd, int prev_fd, int pipe_fd[2])
{
	if (cmd->out_fd != 1)
		dup2(cmd->out_fd, 1);
	else if (cmd->next)
		dup2(pipe_fd[1], 1);
	if (cmd->in_fd != 0)
		dup2(cmd->in_fd, 0);
	else if (prev_fd != -1)
		dup2(prev_fd, 0);
	if (prev_fd != -1)
		close(prev_fd);
	if (cmd->next)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (is_builtin(cmd->list))
		do_builtin(data, cmd->list, 1);
	else
		execute_cmd(data, cmd->list);
	exit(1);
}

int	pipe_and_fork(t_data *data, t_cmd *cmd, int prev_fd, int *pipe_fd)
{
	pid_t	pid;

	if (cmd->next && pipe(pipe_fd) == -1)
		return (perror("pipe"), 0);
	if (!cmd->skip_cmd)
	{
		pid = fork();
		if (pid == 0)
			exec_child(data, cmd, prev_fd, pipe_fd);
		if (!cmd->next)
		{
			waitpid(pid, &data->exit_code, 0);
			if (WIFEXITED(data->exit_code))
				data->exit_code = WEXITSTATUS(data->exit_code);
			else if (WIFSIGNALED(data->exit_code))
				data->exit_code = 128 + WTERMSIG(data->exit_code);
			if (data->exit_code == 131)
				ft_error("Quit (core dumped)\n");
		}
	}
	else if (data->cmd_list->next && !cmd->next && !cmd->list
		&& cmd->in_fd == -1)
		data->exit_code = 0;
	return (1);
}

void	full_execution(t_data *data)
{
	t_cmd	*cmd;
	int		pipe_fd[2];
	int		prev_fd;

	cmd = data->cmd_list;
	if (is_builtin(cmd->list) && !cmd->next && !cmd->skip_cmd)
		return (exec_single_builtin(data, cmd));
	prev_fd = -1;
	while (cmd)
	{
		if (!pipe_and_fork(data, cmd, prev_fd, pipe_fd))
			return ;
		if (prev_fd != -1)
			close(prev_fd);
		if (cmd->next)
			close(pipe_fd[1]);
		if (cmd->next)
			prev_fd = pipe_fd[0];
		else
			prev_fd = -1;
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
}
