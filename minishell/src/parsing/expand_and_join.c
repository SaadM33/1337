/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:02:45 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:36 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_name(char *str)
{
	int	start;
	int	i;

	start = var_index(str) + 1;
	i = start;
	if (str[i] == '?')
		return (ft_strdup("?"));
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (ft_substr(str, start, i - start));
}

// expands all of a token's variables into a single string then turns it
// into a list
char	*mini_expand(char *token, t_data *data)
{
	char *(tmp2), *tmp1, *str;
	int (i);
	if (!has_var(token))
		return (ft_strdup(token));
	str = ft_strdup("");
	i = 0;
	while (has_var(token + i))
	{
		tmp1 = ft_substr(token, i, var_index(token + i));
		tmp2 = ft_strjoin(str, tmp1);
		ft_free(tmp1);
		ft_free(str);
		str = tmp2;
		tmp1 = var_name(token + i);
		tmp2 = ft_getenv(tmp1, data);
		ft_free(tmp1);
		tmp1 = ft_strjoin(str, tmp2);
		ft_free(tmp2);
		ft_free(str);
		str = tmp1;
		i += var_end_index(token + i);
	}
	tmp1 = ft_strdup(token + i);
	return (tmp2 = ft_strjoin(str, tmp1), ft_free(tmp1), ft_free(str), tmp2);
}

t_token	*split_str_to_list(char *str, t_token *node, int *bflag, int *aflag)
{
	t_token (*list);
	char **(arr);
	int (i);
	list = NULL;
	if (node->type == DQ)
		add_token_node(&list, str, 1, 0);
	else
	{
		if (ft_isspace(str[0]) && bflag)
			*bflag = 1;
		i = 0;
		while (str[i] && str[i + 1])
			i++;
		*aflag = ft_isspace(str[i]);
		i = 0;
		arr = ft_split_whitespace(str);
		while (arr[i])
			add_token_node(&list, arr[i++], 1, 0);
		if (!list)
			add_token_node(&list, NULL, 1, 0);
		(ft_free(str), ft_free(arr));
	}
	return (list);
}

t_token	*join_with_next(t_token *list1, t_token *node, t_data *data, int aflag)
{
	t_token *(list2), *tmp;
	char *(temp);
	int (bflag);
	bflag = 0;
	list2 = ft_expand_and_join(node->next, data, aflag >= 2, &bflag);
	if (aflag >= 2)
		aflag -= 2;
	tmp = list1;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!list2->arg)
		free_token_list(&list2);
	else if ((bflag || aflag) && list2->arg && tmp->arg)
		tmp->next = list2;
	else
	{
		if (!tmp->arg)
			tmp->arg = ft_strdup("");
		temp = ft_strjoin(tmp->arg, list2->arg);
		ft_free(tmp->arg);
		tmp->arg = temp;
		tmp->next = list2->next;
		remove_token(&list2, list2);
	}
	return (NULL);
}

t_token	*ft_expand_and_join(t_token *node, t_data *data, int not_expand,
	int *bflag)
{
	t_token	*list1;
	int		aflag;

	aflag = 0;
	list1 = NULL;
	if (!node || node->type == OP || node->type == PP)
		return (node);
	if (node->type == SQ || not_expand)
		add_token_node(&list1, ft_strdup(node->arg), 1, 0);
	else if (node->type == DF || node->type == DQ)
		list1 = split_str_to_list(mini_expand(node->arg, data),
				node, bflag, &aflag);
	if (not_expand)
		aflag += 2;
	if (node->append && node->next)
		join_with_next(list1, node, data, aflag);
	return (list1);
}
