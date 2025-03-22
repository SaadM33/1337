/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:57:52 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/21 23:45:12 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(500);
}

static int	err_msg(void)
{
	write(2, "Error! invalid arguments\n", 26);
	exit(1);
}

int	validate_input(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '\0' || ( av[i][1] != '0' && av[i][0] == '-'))
			err_msg();
		if (av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][1] != '0')
				err_msg();
			j++;
		}
		i++;
	}
	return (1);
}
