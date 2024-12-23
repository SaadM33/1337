
#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc >= 2)
	{
		handle_input(argv, argc, &stack_a);
		
	}
	free_stack(&stack_a);
	return (0);
}



void handle_input(char **av, int ac, t_stack **stack_a)
{
    int     i;
    char    **args;
    int     tmp;

    i = 0;
    if (ac == 2)
        args = ft_split(av[1], ' ');
    else
        args = &av[1];
    while (args[i])
    {
        if (!is_valid_number(args[i]))
			handle_error(stack_a, args, ac);
		if (!check_duplicate(*stack_a, ft_atol(args[i])));
			handle_error(stack_a, args, ac);
		add_to_stack(stack_a, ft_atol(args[i]), args, ac);
        i++;
    }
    if (ac == 2)
        free_split(args);
}





















int check_duplicate(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (0);
        stack = stack->next;
    }
    return (1);
}


void add_to_stack(t_stack **stack, int value, char **args, int ac)
{
    t_stack *new_node;
    t_stack *temp;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        handle_error(stack, args, ac);
    new_node->value = value;
    new_node->next = NULL;
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}



int is_valid_number(char *str)
{
    int     i;
    long    num;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    num = ft_atol(str);
    if (num > INT_MAX || num < INT_MIN)
		return (0);
    return (1);
}



void handle_error(t_stack **stack_a, char **args, int ac)
{
    free_stack(stack_a);
	if (ac == 2)
		free_split(args);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}




void	free_split(char **args)
{
	int	i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}



void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
long ft_atol(const char *str)
{
    int     i;
    int     sign;
    long    result;

    i = 0;
    sign = 1;
    result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
