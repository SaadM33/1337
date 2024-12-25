/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:29:20 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/12/25 09:57:29 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void 	handle_error(t_stack **stack_a, char **args, int ac);
void 	add_to_stack(t_stack **stack, int value, char **args, int ac);
void	free_split(char **args);
void 	free_stack(t_stack **stack);
long	ft_atol(const char *str);
int 	check_duplicate(t_stack *stack, int value);

void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_a, t_stack **stack_b);

void    rot_a(t_stack **stack_a);
void    rot_b(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);

void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

void    revrot_a(t_stack **stack_a);
void    revrot_b(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

#endif
