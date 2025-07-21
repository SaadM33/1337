/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:30:22 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:12 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**remove_var(char **env, char *key);

int	do_unset(t_data *data, t_token *list)
{
	t_token	*args;

	args = list->next;
	while (args)
	{
		if (ft_getenv(args->arg, data))
		{
			data->env = remove_var(data->env, args->arg);
		}
		args = args->next;
	}
	data->exit_code = 0;
	return (1);
}

char	**remove_var(char **env, char *key)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;
	new_env = ft_malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	j = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], key, ft_strlen(key)) != 0
			|| env[i][ft_strlen(key)] != '=')
			new_env[j++] = env[i];
		else
			ft_free(env[i]);
	}
	new_env[j] = NULL;
	ft_free(env);
	return (new_env);
}
