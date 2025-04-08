/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:00:49 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/04/08 18:06:08 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define STR_USAGE	"usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

# define RESET       "\033[0m"
# define RED         "\033[31m"
# define GREEN       "\033[92m"
# define YELLOW      "\033[33m"
# define BLUE        "\033[34m"
# define MAGENTA     "\033[35m"
# define CYAN    	"\033[36m"
# define WHITE       "\033[37m"
# define BOLD        "\033[1m"
# define UNLNE   	"\033[4m"

typedef struct s_info
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long			start_time;
	int				sim_stop;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	sim_lock;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_eaten;
	long			t_last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
}	t_philo;

// INPUT HANDLING
int		validate_input(char **av);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

// initialisation
int		init_info(char **av, t_info *info);
int		init_philo(t_info *info, t_philo **philos);
void	start_slaves(t_info *info, t_philo *philos);

// main functions
void	*routine(void *tmp_ph);
int		take_fork(t_philo *philo, t_info *info);
int		eat(t_philo *philo, t_info *info);
void	*behold(void *tmp_info);
void	*check_philosopher(t_info *info, int i);
int		print_handler(char msg, t_philo *philo, int fork);

// helper stuff
long	get_time(void);
void	ft_usleep(long time, t_info *info);
void	cleanup(t_info *info, t_philo *philos, pthread_t *old_one);

#endif