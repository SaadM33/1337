/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:42 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:05 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

static int	ft_isspace(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	ft_atoi(const char *s)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == 43 || s[i] == 45)
		if (s[i++] == 45)
			sign = -1;
	while (ft_isdigit(s[i]))
		result = (result * 10) + s[i++] - 48;
	return ((int)(result * sign));
}
