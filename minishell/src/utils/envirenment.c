/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirenment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:00:27 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/18 19:53:17 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dupenv(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = ft_calloc(i + 1, sizeof(char *));
	if (!new_env)
		(perror("minishell"), ft_exit(errno));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
			(perror("minishell"), ft_exit(errno));
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	*ft_getenv(char *key, t_data *data)
{
	int		i;
	int		keylen;
	char	*out;
	char	**env;

	i = 0;
	keylen = ft_strlen(key);
	env = data->env;
	out = NULL;
	if (!ft_strcmp(key, "?"))
		return (ft_itoa(data->exit_code));
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, keylen) && env[i][keylen] == '=')
			out = ft_strdup(env[i] + keylen + 1);
		i++;
	}
	if (!out)
		out = ft_strdup("");
	return (out);
}

void	sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[j + 1])
		{
			if (ft_strcmp(env[j], env[j + 1]) > 0)
			{
				tmp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_setenv(char ***env, char *key, char *val)
{
	int		i;
	char	**new_env;
	char	*entry;

	entry = ft_strjoin3(key, "=", val);
	i = -1;
	while ((*env)[++i])
	{
		if (!ft_strncmp((*env)[i], key, ft_strlen(key))
			&& (*env)[i][ft_strlen(key)] == '=')
		{
			ft_free((*env)[i]);
			(*env)[i] = entry;
			return ;
		}
	}
	new_env = ft_malloc(sizeof(char *) * (i + 2));
	i = -1;
	while ((*env)[++i])
		new_env[i] = (*env)[i];
	new_env[i++] = entry;
	new_env[i] = NULL;
	(ft_free(*env), *env = new_env);
}

void	ft_remvar(char *key, char ***env)
{
	int		i;

	i = 0;
	while ((*env)[i])
	{
		if (!ft_strncmp((*env)[i], key, ft_strlen(key)) &&
			(*env)[i][ft_strlen(key)] == '=')
		{
			free((*env)[i]);
			i++;
			while ((*env)[i])
			{
				(*env)[i - 1] = (*env)[i];
				i++;
			}
			(*env)[i - 1] = NULL;
			return ;
		}
		i++;
	}
}
