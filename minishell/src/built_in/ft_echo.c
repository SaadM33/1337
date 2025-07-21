/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:22:38 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/18 10:48:58 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	n_only(t_token *node, int *flag)
{
	int	i;

	i = 0;
	if (!node || !node->arg || node->arg[0] != '-')
		return (0);
	if (node->arg[0] == '-' && node->arg[1] == 'n')
		i++;
	while (node->arg[i])
	{
		if (node->arg[i] != 'n')
			return (0);
		i++;
	}
	*flag = 1;
	return (1);
}

int	do_echo(t_data *data, t_token *list)
{
	t_token	*cd_args;
	int		had_n;

	data->exit_code = 0;
	had_n = 0;
	cd_args = list->next;
	if (!cd_args)
		return (printf("\n"), 1);
	while (cd_args)
	{
		if (n_only(cd_args, &had_n))
			cd_args = cd_args->next;
		else
			break ;
	}
	while (cd_args)
	{
		printf("%s", cd_args->arg);
		if (cd_args->next)
			printf(" ");
		cd_args = cd_args->next;
	}
	if (!had_n)
		printf("\n");
	return (1);
}
