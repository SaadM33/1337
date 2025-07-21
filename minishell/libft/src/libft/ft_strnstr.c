/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:22:05 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:45 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	llen;

	i = 0;
	if (little[0] == 0)
		return ((char *) big);
	if (len == 0 || big[0] == 0)
		return (NULL);
	llen = ft_strlen(little);
	while (i + llen <= len && big[i] != 0)
	{
		j = 0;
		while (big[i + j] == little[j] && j < llen)
			j++;
		if (j == llen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
