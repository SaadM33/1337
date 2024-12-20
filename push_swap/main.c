
#include "push_swap.h"
#include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

int	main(int argc, char **argv)
{
	int i;
	int temp;
	int *numbers;

	i = 1;
	if (argc >= 2)
	{
		numbers = handle_input(argv, argc);
		if (check_input(numbers) = -1)
		{
			
		}
	}
	return (0);
}

int*	handle_input(char **av, int ac)
{
	int		i;
	char	**args;
	int		tmp;

	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		check_input(args);
		while (args[i])
		{
			tmp = ft_atoi(args[i]);
		}
	}
}
int check_input(char **args)
{
	int	i;

	i = 0;

}
int isValid(char *s)
