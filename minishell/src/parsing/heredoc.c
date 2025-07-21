/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:13:39 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:51 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_heredoc(t_data *data, t_cmd *cmd)
{
	t_token	*curr;

	while (cmd)
	{
		curr = cmd->list;
		while (curr)
		{
			if (curr->type == OP && !ft_strcmp(curr->arg, "<<"))
			{
				close_prev_fd(cmd, 0);
				if (ft_heredoc(curr->next, cmd, data))
					return (0);
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

char	*ft_heredoc_name(int c)
{
	char	*char_buff;
	char	*name;
	char	*path;
	int		fd;
	int		i;

	name = ft_calloc(HEREDOC_SIZE + 1, sizeof(char));
	fd = open("/dev/urandom", O_RDONLY);
	char_buff = "2>ND{e:~mn7G`<kW6h^_IuAOw&#\\}y"
		"aszM]btp?8@3%L$9J*4Kd!j[g5lfrRH0Y(ox;SE\"cXU1CQv|)F=q+T'-VZBP,i";
	if (fd == -1)
		return (perror("minishell: open"), ft_free(name), NULL);
	i = 0;
	while (i < HEREDOC_SIZE)
	{
		if (read(fd, &c, 1) == -1)
			return (perror("minishell: read"), ft_free(name), close(fd), NULL);
		name[i] = char_buff[c % ft_strlen(char_buff)];
		i++;
	}
	close(fd);
	name[i] = '\0';
	path = ft_strjoin("/tmp/", name);
	return (ft_free(name), path);
}

void	heredoc_read_loop(t_token *node, int fd, int should_expand,
		t_data *data)
{
	char	*str;
	char	*str2;

	str = readline("> ");
	if (!str)
	{
		close(fd);
		ft_error3("minishell: warning: here-document delimited by "
			"end-of-file (wanted `", node->arg, "')\n");
		ft_exit(0);
	}
	if (!ft_strcmp(str, node->arg))
		(close(fd), ft_exit(0));
	if (should_expand)
	{
		str2 = mini_expand(str, data);
		ft_free(str);
		str = str2;
	}
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	ft_free(str);
}

int	ft_fork_heredoc(t_token *node, int wr_fd, int rd_fd, int should_expand)
{
	int		pid;
	int		status;
	t_data	*data;

	data = get_data();
	pid = fork();
	if (pid == -1)
		return (perror("minishell: fork"), data->exit_code = 1, 1);
	status = 0;
	if (!pid)
	{
		close(rd_fd);
		get_fd(&wr_fd);
		signal(SIGINT, heredoc_sig_handler);
		while (1)
			heredoc_read_loop(node, wr_fd, should_expand, data);
	}
	(close(wr_fd), wait(&status));
	if (WIFSIGNALED(status))
		return (data->exit_code = WTERMSIG(status) + 128, 1);
	else
		data->exit_code = WEXITSTATUS(status);
	if (data->exit_code == 130)
		return (1);
	return (0);
}

int	ft_heredoc(t_token *node, t_cmd *cmd, t_data *data)
{
	char	*heredoc_name;

	int (wr_fd), rd_fd, should_expand, is_last_redirect;
	should_expand = ft_should_expand(node);
	is_last_redirect = last_in_redirection(cmd, node);
	node = ft_expand_and_join(node, data, 1, NULL);
	heredoc_name = ft_heredoc_name(0);
	if (!heredoc_name)
		return (data->exit_code = 1, free_token_list(&node), -1);
	wr_fd = open(heredoc_name, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (wr_fd == -1)
		return (perror("minishell: open"), data->exit_code = 1,
			ft_free(heredoc_name), free_token_list(&node), -1);
	rd_fd = open(heredoc_name, O_RDONLY);
	if (rd_fd == -1)
		return (perror("minishell: open"), data->exit_code = 1,
			ft_free(heredoc_name), free_token_list(&node), close(wr_fd), -1);
	(unlink(heredoc_name), ft_free(heredoc_name));
	if (ft_fork_heredoc(node, wr_fd, rd_fd, should_expand))
		return (free_token_list(&node), close(rd_fd), -1);
	if (is_last_redirect)
		cmd->in_fd = rd_fd;
	else
		close(rd_fd);
	return (free_token_list(&node), 0);
}
