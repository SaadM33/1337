/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:01:11 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:00 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isdelimiter(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13) || c == '<'
		|| c == '>' || c == '|' || c == '"' || c == '\'' || !c);
}

int	ft_isoperator(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

int	ft_isquote(char c)
{
	return (c == '"' || c == '\'');
}
