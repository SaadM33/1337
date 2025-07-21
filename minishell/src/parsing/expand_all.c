/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:19:27 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:29 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_add_back(t_token **head, t_token *node)
{
	t_token	*tmp;

	if (!head || !node)
		return ;
	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void	expand_all(t_data *data)
{
	t_cmd	*cmd;
	t_token	*new_list;
	t_token	*tmp1;
	t_token	*tmp2;

	cmd = data->cmd_list;
	while (cmd)
	{
		new_list = NULL;
		tmp1 = cmd->list;
		while (tmp1)
		{
			tmp2 = ft_expand_and_join(tmp1, data, 0, NULL);
			if (!tmp2 || (tmp2 && !tmp2->arg))
				free_token_list(&tmp2);
			else
				token_add_back(&new_list, tmp2);
			while (tmp1 && tmp1->append && tmp1->next)
				tmp1 = tmp1->next;
			tmp1 = tmp1->next;
		}
		free_token_list(&cmd->list);
		cmd->list = new_list;
		cmd = cmd->next;
	}
}

int	has_var(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '$');
	while (tmp && !ft_isalpha(tmp[1]) && tmp[1] != '_' && tmp[1] != '?')
		tmp = ft_strchr(tmp + 1, '$');
	return (tmp != 0);
}

int	var_index(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '$');
	while (tmp && !ft_isalpha(tmp[1]) && tmp[1] != '_' && tmp[1] != '?')
		tmp = ft_strchr(tmp + 1, '$');
	if (tmp)
		return (tmp - str);
	return (0);
}

int	var_end_index(char *str)
{
	char	*tmp;

	tmp = str + var_index(str) + 1;
	if (*tmp == '?')
		return (tmp + 1 - str);
	while (ft_isalnum(*tmp) || *tmp == '_')
		tmp++;
	return (tmp - str);
}
