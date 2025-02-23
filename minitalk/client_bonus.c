/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:57:03 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/23 18:17:01 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_ack(int sig)
{
	(void)sig;
}

void	msg_to_signal(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		pause();
		// usleep(300);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	ser_pid;

	if (ac != 3)
		return (ft_printf("Usage: ./client \"server PID\"  \"MSG\" \n"));
	ser_pid = ft_atoi(av[1]);
	if (kill(ser_pid, 0) == -1)
		return (ft_printf("Error: Invalid PID\n"));
	signal(SIGUSR1, handle_ack);
	i = 0;
	while (av[2][i])
	{
		msg_to_signal(av[2][i], ser_pid);
		i++;
	}
	msg_to_signal('\n', ser_pid);
	return (0);
}
