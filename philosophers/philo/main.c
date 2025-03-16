/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:39:16 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/16 02:06:28 by sel-maaq         ###   ########.fr       */
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
}

void	init_philo(t_info *info, t_philo **philos)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * info->n_philo);
	if (!philos)
	{
		cleanup(info, *philos);
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
} 
void	routine(void *phil)
{
	t_philo philo;

	philo = (t_philo)*phil;
	printf("hi im philosofer %d\n", philo.id);
}

void start_nibbas(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_create(&philos[i].thread, NULL, routine, philos[i]);
		i++;
	}
	
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (printf(STR_USAGE), 1);
	validate_input(av);
	init_info(av, &info);
	init_philo(&info, &philos);
	info.start_time = get_time();
	start_nibbas();
	
	cleanup(&info, philos);
	return (0);
}

void	cleanup(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->write_lock);
	
	free(info->forks);
	free(philos);
}
