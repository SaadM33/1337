/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:35 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/23 22:06:37 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_to_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	n;
	static unsigned int		i;

	(void)context;
	if (sig == SIGUSR2)
	{
		n = (n << 1) | 1;
	}
	else
	{
		n = (n << 1) | 0;
	}
	i++;
	usleep(200);
	kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		ft_printf("%c", n);
		n = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void)av;
	if (ac != 1)
		return (ft_printf("Error, no arguments needed\n"), 1);
	pid = getpid();
	ft_printf("PID of the server is : %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_to_msg;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
