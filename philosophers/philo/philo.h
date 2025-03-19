#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define STR_USAGE	"usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define WHITE       "\033[37m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

typedef struct s_info
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long			start_time;
	int				sim_stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
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






int		validate_input(char **av);

void	init_info(char **av, t_info *info);
void	init_philo(t_info *info, t_philo **philos);




long	get_time(void);
void	ft_usleep(long time);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);


void	cleanup(t_info *info, t_philo *philos);

#endif