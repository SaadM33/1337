/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:39:00 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/04/07 22:07:10 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *tmp_ph)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)tmp_ph;
	info = (t_info *)philo->info;
	if (info->n_philo == 1)
	{
		print_handler('f', philo, 0);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		usleep(20000);
	while (1)
	{
		if (!eat(philo, info))
			return (NULL);
		if (!print_handler('s', philo, 0))
			return (NULL);
		ft_usleep(info->t_sleep, info);
		if (!print_handler('t', philo, 0))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

int	eat(t_philo *philo, t_info *info)
{
	if (info->n_meals != -1 && philo->n_eaten >= info->n_meals)
		return (0);
	if (philo->id != info->n_philo)
	{
		pthread_mutex_lock(philo->left_fork);
		if (!print_handler('f', philo, 1))
			return (0);
		pthread_mutex_lock(philo->right_fork);
		if (!print_handler('f', philo, 2))
			return (0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (!print_handler('f', philo, 3))
			return (0);
		pthread_mutex_lock(philo->left_fork);
		if (!print_handler('f', philo, 4))
			return (0);
	}
	if (!print_handler('e', philo, 4))
		return (0);
	pthread_mutex_lock(&info->sim_lock);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&info->sim_lock);
	ft_usleep(info->t_eat, info);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&info->sim_lock);
	philo->n_eaten++;
	pthread_mutex_unlock(&info->sim_lock);
	if (info->n_meals != -1 && philo->n_eaten >= info->n_meals)
		return (0);
	return (1);
}

void	*behold(void *tmp_info)
{
	t_info	*info;
	int		i;
	long	t_stamp;
	int		full_philos;

	info = (t_info *)tmp_info;
	while (info->sim_stop != 1)
	{
		i = 0;
		full_philos = 0;
		while (i < info->n_philo)
		{
			pthread_mutex_lock(&info->sim_lock);
			t_stamp = get_time() - info->philos[i].t_last_meal;
			if (info->philos[i].n_eaten == info->n_meals)
				full_philos++;
			if (t_stamp >= info->t_die && info->philos[i].n_eaten != \
				info->n_meals)
			{
				info->sim_stop = 1;
				pthread_mutex_unlock(&info->sim_lock);
				return (print_handler('d', &info->philos[i], 0), NULL);
			}
			pthread_mutex_unlock(&info->sim_lock);
			i++;
		}
		if (full_philos == info->n_philo)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philos;
	pthread_t	watcher;

	if (ac < 5 || ac > 6)
		return (printf(STR_USAGE), 1);
	if (!validate_input(av))
		return (1);
	if (!init_info(av, &info))
		return (1);
	if (!init_philo(&info, &philos))
		return (1);
	info.start_time = get_time();
	start_slaves(&info, philos);
	pthread_create(&watcher, NULL, behold, &info);
	cleanup(&info, philos, &watcher);
	return (0);
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
