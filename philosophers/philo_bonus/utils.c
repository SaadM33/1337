/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:05:51 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/04/08 17:26:09 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_philosopher(t_info *info, int i)
{
	pthread_mutex_lock(&info->sim_lock);
	if ((get_time() - info->philos[i].t_last_meal >= info->t_die)
		&& info->philos[i].n_eaten != info->n_meals)
	{
		info->sim_stop = 1;
		pthread_mutex_unlock(&info->sim_lock);
		return (print_handler('d', &info->philos[i], 0), NULL);
	}
	pthread_mutex_unlock(&info->sim_lock);
	return ((void *)1);
}

int	take_fork(t_philo *philo, t_info *info)
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
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
