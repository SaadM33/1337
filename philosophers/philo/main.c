/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:39:16 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/22 00:34:57 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop(t_info *info)
{
	int	stop;

	pthread_mutex_lock(&info->sim_lock);
	stop = info->sim_stop;
	pthread_mutex_unlock(&info->sim_lock);
	return (stop);
}

void	*routine(void *tmp_ph)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)tmp_ph;
	info = (t_info *)philo->info;
	while (1)
	{
		eat(philo, info);
		print_handler('s', philo);
		ft_usleep(info->t_sleep);
		print_handler('t', philo);
	}
	return (NULL);
}

void	eat(t_philo *philo, t_info *info)
{
	if (philo->id != info->n_philo)
	{
		pthread_mutex_lock(philo->left_fork);
		print_handler('f', philo);
		pthread_mutex_lock(philo->right_fork);
		print_handler('f', philo);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_handler('f', philo);
		pthread_mutex_lock(philo->left_fork);
		print_handler('f', philo);
	}
	print_handler('e', philo);
	pthread_mutex_lock(&info->sim_lock);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&info->sim_lock);
	ft_usleep(info->t_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->n_eaten++;
	if (info->n_meals != -1 && philo->n_eaten == info->n_meals)
		pthread_exit(NULL);
}

void	*behold(void *tmp_info)
{
	int		i;
	t_info	*info;
	long	t_stamp;

	info = (t_info *)tmp_info;
	while (info->sim_stop != 1)
	{
		i = 0;
		while (i < info->n_philo)
		{
			pthread_mutex_lock(&info->sim_lock);
			t_stamp = get_time() - info->philos[i].t_last_meal;
			pthread_mutex_unlock(&info->sim_lock);
			if (t_stamp >= info->t_die && info->philos[i].n_eaten != info->n_meals)
			{
				pthread_mutex_lock(&info->sim_lock);
				info->sim_stop = 1;
				pthread_mutex_unlock(&info->sim_lock);
				return (print_handler('d', &info->philos[i]), NULL);
			}
			i++;
		}
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
	validate_input(av);
	init_info(av, &info);
	init_philo(&info, &philos);
	info.start_time = get_time();
	start_slaves(&info, philos);
	pthread_create(&watcher, NULL, behold, &info);
	cleanup(&info, philos, &watcher);
	// system("paplay ~/1337/so_long/assets/dry-fart.wav");
	return (0);
}

