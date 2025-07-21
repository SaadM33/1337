/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:18:59 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/07/16 21:45:49 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_data *data)
{
	int	res;

	res = lexer(data);
	ft_free(data->str);
	data->str = NULL;
	if (!syntax_checker(data, res))
		return (free_token_list(&data->token_list), 0);
	list_to_cmds(data);
	free_token_list(&data->token_list);
	if (!handle_heredoc(data, data->cmd_list))
		return (free_cmd_list(&data->cmd_list), 0);
	handle_redirections(data, data->cmd_list);
	expand_all(data);
	return (1);
}
