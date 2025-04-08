/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:57:52 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:43 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long time, t_info *info)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		pthread_mutex_lock(&info->sim_lock);
		if (info->sim_stop)
		{
			pthread_mutex_unlock(&info->sim_lock);
			break ;
		}
		pthread_mutex_unlock(&info->sim_lock);
		usleep(500);
	}
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
		if (av[i][0] == '\0' || (av[i][1] != '0' && av[i][0] == '-'))
			return (write(2, "Error! invalid arguments\n", 26), 0);
		if (av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][1] != '0')
				return (write(2, "Error! invalid arguments\n", 26), 0);
			j++;
		}
		i++;
	}
	return (1);
}
