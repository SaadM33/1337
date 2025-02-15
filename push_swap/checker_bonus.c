/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:25:58 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/14 21:46:50 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	handle_input(argv, &a);
	line = get_next_line(0, 0);
	while (line)
	{
		execute_inst(line, &a, &b);
		free(line);
		line = get_next_line(0, 0);
	}
	if (is_sorted(a) && get_stack_size(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	if (line)
		free(line);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	execute_inst(char *op, t_stack **a, t_stack **b)
{
	size_t	len;

	len = ft_strlen(op);
	if (len > 0 && op[len - 1] == '\n')
		op[len - 1] = '\0';
	if (ft_strcmp(op, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(a, b);
	else
		execute_inst_extra(op, a, b);
}

void	execute_inst_extra(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "ra") == 0)
		rot_a(a);
	else if (ft_strcmp(op, "rb") == 0)
		rot_b(b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		revrot_a(a);
	else if (ft_strcmp(op, "rrb") == 0)
		revrot_b(b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(op);
		free_stack(a);
		free_stack(b);
		get_next_line(0, 1);
		exit(1);
	}
}
