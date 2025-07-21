/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:21:35 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:40 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;

	len = ft_strlen(s);
	result = ft_malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s, len);
	result[len] = 0;
	return (result);
}
