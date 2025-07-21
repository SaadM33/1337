/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 03:19:37 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/17 21:06:40 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		ft_free(table[i]);
		i++;
	}
	ft_free(table);
}

int	ft_in_env(char *key, t_data *data)
{
	int		i;
	int		keylen;
	int		out;
	char	**env;

	i = 0;
	keylen = ft_strlen(key);
	env = data->env;
	out = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, keylen) && env[i][keylen] == '=')
			out = 1;
		i++;
	}
	return (out);
}

char	*ft_strjoin3(char *str1, char *middle, char *str2)
{
	char	*tmp;
	char	*full_result;

	tmp = ft_strjoin(str1, middle);
	full_result = ft_strjoin(tmp, str2);
	ft_free(tmp);
	return (full_result);
}

int	*get_status(void)
{
	static int	flag;

	return (&flag);
}
