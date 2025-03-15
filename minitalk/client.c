/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:23:25 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/07 23:03:45 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_to_signal(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
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
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		msg_to_signal(av[2][i], ser_pid);
		i++;
	}
	msg_to_signal('\n', ser_pid);
	return (0);
}
