/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:49:03 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:44 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (!f || !s)
		return (NULL);
	out = ft_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
