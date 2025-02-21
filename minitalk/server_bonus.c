/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:35 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/21 18:55:51 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_to_msg(int sig)
{
	static unsigned char	n;
	static unsigned int		i;
	if (sig == SIGUSR1)
		n = (n << 1) | 0;
	else
		n = (n << 1) | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", n);
		n = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error, no arguments needed\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID of the server is : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_to_msg);	
		signal(SIGUSR2, signal_to_msg);
		pause();
	}
}