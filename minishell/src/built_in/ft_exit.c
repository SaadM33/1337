/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:24:56 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/18 20:25:16 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_strict_num(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_exit_code(char *str, long long *result)
{
	int			sign;
	__int128_t	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		if ((sign == 1 && num > LLONG_MAX)
			|| (sign == -1 && (-num < LLONG_MIN)))
			return (0);
		str++;
	}
	*result = num * sign;
	return (1);
}

int	do_exit(t_data *data, t_token *list)
{
	t_token		*arg;
	long long	exit_status;

	if (data->cmd_list && !data->cmd_list->next)
		ft_error("exit\n");
	arg = list->next;
	if (arg)
	{
		if (!is_strict_num(arg->arg)
			|| !parse_exit_code(arg->arg, &exit_status))
		{
			ft_error3("minishell: exit: ", arg->arg,
				": numeric argument required\n");
			ft_exit(2);
		}
		if (arg->next)
			return (ft_error("minishell: exit: too many arguments\n"),
				data->exit_code = 1, 1);
	}
	else
		exit_status = data->exit_code;
	ft_exit((unsigned char)exit_status);
	return (1);
}
