/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:05:27 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:05 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_alloc_size(char *str, int i)
{
	return (str[i] == str[i + 1] && str[i + 1] != '|');
}

int	lexer3(t_data *data, int *ft_flag, int *i, char *quote)
{
	*ft_flag = 1;
	if (!ft_isdelimiter(data->str[*i]))
	{
		*quote = 0;
		return (*i);
	}
	else if (ft_isquote(data->str[*i]))
	{
		*quote = data->str[*i];
		return (*i + 1);
	}
	return (*i);
}

int	lexer2(t_data *data, char quote, int start, int *i)
{
	if (!quote && ft_isdelimiter(data->str[*i]))
	{
		add_token_node(&data->token_list, ft_substr(data->str,
				start, *i - start), 0, ft_isquote(data->str[*i]));
		return (0);
	}
	else if (quote && data->str[*i] == quote)
	{
		add_token_node(&data->token_list, ft_substr(data->str, start,
				(*i) - start), 1 + (data->str[*i] == '"'),
			!ft_isdelimiter(data->str[(*i) + 1])
			|| ft_isquote(data->str[(*i) + 1]));
		(*i)++;
		return (0);
	}
	return (1);
}

int	lexer(t_data *data)
{
	char (qt), (*str);
	int (ft_flag), start, i;
	ft_flag = 0;
	i = 0;
	str = data->str;
	while (str[i])
	{
		if (!ft_flag && (!ft_isdelimiter(str[i]) || ft_isquote(str[i])))
			start = lexer3(data, &ft_flag, &i, &qt);
		else if (!ft_flag && ft_isoperator(str[i]))
		{
			start = i;
			add_token_node(&data->token_list, ft_substr(str, start,
					1 + ft_alloc_size(str, i)), 3 + (str[i] == '|'), 0);
			i += ft_alloc_size(str, i);
		}
		i++;
		if (ft_flag && (ft_isdelimiter(str[i]) || str[i] == qt))
			ft_flag = lexer2(data, qt, start, &i);
	}
	if (ft_flag)
		return (qt);
	return (0);
}
