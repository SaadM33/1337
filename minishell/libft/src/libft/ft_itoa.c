/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:11:08 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:19 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*fill(char *out, long n)
{
	int		i;
	long	x;

	i = 0;
	x = 1;
	if (n < 0)
	{
		out[i] = '-';
		n *= -1;
		i++;
	}
	while ((x * 10) <= n)
		x *= 10;
	while (x > 0)
	{
		out[i] = ('0' + (n / x) % 10);
		i++;
		x /= 10;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_itoa(int n0)
{
	char	*out;
	int		i;
	long	n;

	n = n0;
	i = ft_size(n);
	out = ft_malloc(sizeof(char) * (i + 1));
	if (out == NULL)
		return (NULL);
	fill(out, n);
	return (out);
}
