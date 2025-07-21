/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:26:25 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:18 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	syn_error(t_data *data, char *arg)
{
	if (arg && *arg == '"')
		ft_error3("unexpected EOF while looking for matching `", "\"", "'\n");
	else if (arg && *arg == '\'')
		ft_error3("unexpected EOF while looking for matching `", "'", "'\n");
	else if (!arg)
		ft_error("syntax error near unexpected token `newline'\n");
	else
		ft_error3("syntax error near unexpected token `", arg, "'\n");
	data->exit_code = 2;
	return (0);
}

int	syntax_checker(t_data *data, char unmatched_quote)
{
	t_token	*current;
	t_token	*next;

	current = data->token_list;
	if (unmatched_quote)
		return (syn_error(data, &unmatched_quote), 0);
	if (!current)
		return (0);
	if (data->token_list->type == PP)
		return (syn_error(data, data->token_list->arg), 0);
	while (current)
	{	
		next = current->next;
		if ((current->type == OP || current->type == PP) && !next)
			return (syn_error(data, NULL), 0);
		else if (current->type == OP && (next->type == OP || next->type == PP))
			return (syn_error(data, next->arg), 0);
		else if (current->type == PP && next->type == PP)
			return (syn_error(data, next->arg), 0);
		current = current->next;
	}
	return (1);
}
