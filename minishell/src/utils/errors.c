/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:55:21 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:48 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// error function that write given strings to the std error
// TODO look back at them to make sure they work well with ft_malloc

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_error2(char *str1, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str1, str2);
	if (tmp)
	{
		ft_error(tmp);
		ft_free(tmp);
	}
	else
	{
		ft_error(str1);
		ft_error(str2);
	}
}

void	ft_error3(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strjoin(str1, str2);
	tmp1 = ft_strjoin(tmp, str3);
	ft_free(tmp);
	if (tmp1)
	{
		ft_error(tmp1);
		ft_free(tmp1);
	}
	else
	{
		ft_error(str1);
		ft_error(str2);
		ft_error(str3);
	}
}

void	ft_error4(char *str1, char *str2, char *str3, char *str4)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	tmp = ft_strjoin(str1, str2);
	tmp1 = ft_strjoin(tmp, str3);
	tmp2 = ft_strjoin(tmp1, str4);
	ft_free(tmp);
	ft_free(tmp1);
	if (tmp2)
	{
		ft_error(tmp2);
		ft_free(tmp2);
	}
	else
	{
		ft_error(str1);
		ft_error(str2);
		ft_error(str3);
		ft_error(str4);
	}
}
