/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:46:07 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:09:46 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_word_count(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
		if (!ft_isspace(s[i++]) && (ft_isspace(s[i]) || s[i] == 0))
			count++;
	return (count);
}

static char	*ft_strcdup(const char *s)
{
	int		len;
	char	*result;

	len = 0;
	while (s[len] != 0 && !ft_isspace(s[len]))
		len++;
	result = ft_malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s, len);
	result[len] = 0;
	return (result);
}

static void	freestrs(char **s, int i)
{
	while (i > 0)
	{
		ft_free(s[i - 1]);
		i--;
	}
	ft_free(s);
}

static void	fill(char *s, char **out)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	x = 1;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && x == 1)
		{
			x = 0;
			out[j] = ft_strcdup(&s[i]);
			if (!out[j])
				freestrs(out, j);
			j++;
		}
		if (ft_isspace(s[i]))
			x = 1;
		i++;
	}
	out[j] = NULL;
}

char	**ft_split_whitespace(char const *s)
{
	char	**out;

	if (!s)
		return (NULL);
	out = ft_malloc(sizeof(char *) * (ft_word_count(s) + 1));
	if (!out)
		return (NULL);
	fill((char *)s, out);
	return (out);
}
