/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:58:02 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/04/07 15:02:23 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(char **av, t_info *info)
{
	int	i;

	info->n_philo = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	if (av[5])
		info->n_meals = ft_atoi(av[5]);
	else
		info->n_meals = -1;
	info->sim_stop = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->forks)
		return (0);
	i = 0;
	while (i < info->n_philo)
		pthread_mutex_init(&info->forks[i++], NULL);
	pthread_mutex_init(&info->write_lock, NULL);
	pthread_mutex_init(&info->sim_lock, NULL);
	return (1);
}

int	init_philo(t_info *info, t_philo **philos)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * info->n_philo);
	if (!(*philos))
	{
		cleanup(info, *philos, NULL);
		return (0);
	}
	i = 0;
	while (i < info->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].n_eaten = 0;
		(*philos)[i].t_last_meal = get_time();
		(*philos)[i].info = info;
		(*philos)[i].left_fork = &info->forks[i];
		(*philos)[i].right_fork = &info->forks[(i + 1) % info->n_philo];
		i++;
	}
	info->philos = *philos;
	return (1);
}

void	start_slaves(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
}

int	check_fork(char msg, t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->info->sim_lock);
	if (philo->info->sim_stop == 1 && msg != 'd')
	{
		pthread_mutex_unlock(&philo->info->sim_lock);
		if (fork == 1)
			pthread_mutex_unlock(philo->left_fork);
		else if (fork == 2)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
		else if (fork == 3)
			pthread_mutex_unlock(philo->right_fork);
		else if (fork == 4)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
		return (0);
	}
	pthread_mutex_unlock(&philo->info->sim_lock);
	return (1);
}

int	print_handler(char msg, t_philo *philo, int fork)
{
	long	t_stamp;

	if (check_fork(msg, philo, fork) == 0)
		return (0);
	t_stamp = get_time() - philo->info->start_time;
	pthread_mutex_lock(&philo->info->write_lock);
	if (msg == 'f')
		printf(CYAN "%04ld %d has taken a fork\n" RESET, t_stamp, philo->id);
	else if (msg == 'e')
		printf(GREEN BOLD UNLNE"%04ld %d is eating\n" RESET, t_stamp, philo->id);
	else if (msg == 's')
		printf(BOLD"\033[90m%04ld %d is sleeping\n" RESET, t_stamp, philo->id);
	else if (msg == 't')
		printf(YELLOW "%04ld %d is thinking\n" RESET, t_stamp, philo->id);
	else if (msg == 'd')
		printf(RED"%04ld %d has died\n"RESET, t_stamp, philo->id);
	pthread_mutex_unlock(&philo->info->write_lock);
	return (1);
}
