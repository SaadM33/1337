/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:42 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:37 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

static size_t	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
		if (s[i++] != c && (s[i] == c || s[i] == 0))
			count++;
	return (count);
}

static char	*ft_strcdup(const char *s, char c)
{
	int		len;
	char	*result;

	len = 0;
	while (s[len] != 0 && s[len] != c)
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

static void	fill(char *s, char **out, char c)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	x = 1;
	while (s[i])
	{
		if (s[i] != c && x == 1)
		{
			x = 0;
			out[j] = ft_strcdup(&s[i], c);
			if (!out[j])
				freestrs(out, j);
			j++;
		}
		if (s[i] == c)
			x = 1;
		i++;
	}
	out[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (!s)
		return (NULL);
	out = ft_malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!out)
		return (NULL);
	fill((char *)s, out, c);
	return (out);
}
