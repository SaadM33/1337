/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:58:02 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/21 23:25:06 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(char **av, t_info *info)
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
		exit(EXIT_FAILURE);
	i = 0;
	while (i < info->n_philo)
		pthread_mutex_init(&info->forks[i++], NULL);
	pthread_mutex_init(&info->write_lock, NULL);
	pthread_mutex_init(&info->sim_lock, NULL);
}

void	init_philo(t_info *info, t_philo **philos)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * info->n_philo);
	if (!(*philos))
	{
		cleanup(info, *philos, NULL);
		exit(EXIT_FAILURE);
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

void	print_handler(char msg, t_philo *philo)
{
	long	t_stamp;

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
}

void	cleanup(t_info *info, t_philo *philos, pthread_t *watcher)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
		pthread_join(philos[i++].thread, NULL);
	pthread_join(*watcher, NULL);
	i = 0;
	while (i < info->n_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->write_lock);
	pthread_mutex_destroy(&info->sim_lock);
	free(info->forks);
	free(philos);
}
