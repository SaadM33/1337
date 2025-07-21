/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:43:01 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:11:04 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	t_data	*data;

	data = get_data();
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		if (!*get_status())
		{
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			data->exit_code = 130;
		}
		return ;
	}
}

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	get_fd(int	*ptr)
{
	static int	*fd;

	if (ptr)
		fd = ptr;
	return (*fd);
}

void	heredoc_sig_handler(int sig)
{
	close(get_fd(NULL));
	ft_exit(128 + sig);
}
