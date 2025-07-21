/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:24:07 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/18 10:47:42 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd(t_data *data)
{
	char	cwd[4096];

	data->exit_code = 0;
	if (getcwd(cwd, sizeof(cwd)) == NULL && !data->cwd)
	{
		ft_error2("pwd: error retrieving current directory: getcwd: cannot ",
			"access parent directories: No such file or directory\n");
		data->exit_code = 1;
	}
	else
		printf("%s\n", data->cwd);
	return (1);
}
