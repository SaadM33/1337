#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	handle_input(char **av, int ac, t_stack **stack_a);
int		is_valid_number(char *str);
void	add_to_stack(t_stack **stack, int value, char **args, int ac);
void	handle_error(t_stack **stack, char **args);
void	free_split(char **args);
long	ft_atol(const char *str);


#endif
