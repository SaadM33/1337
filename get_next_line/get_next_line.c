/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:21:42 by sel-maaq          #+#    #+#             */
/*   Updated: 2024/11/15 22:36:53 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save = read_n_save(fd, save, buffer);
	res = extract_line_reload(&save, check_newline(save));
	if (!res)
		return (NULL);
	return (res);
}

char	*read_n_save(int fd, char *save, char	*buffer)
{
	char	*tmp;
	int		null_pos;

	while (!check_newline(save))
	{
		null_pos = read(fd, buffer, BUFFER_SIZE);
		if (null_pos <= 0)
		{
			free(buffer);
			if (!save || *save == '\0')
			{
				free(save);
				return (NULL);
			}
			return (save);
		}
		buffer[null_pos] = '\0';
		tmp = save;
		if (save == NULL)
			save = ft_strdup(buffer);
		else
			save = ft_strjoin(save, buffer);
		free(tmp);
	}
	return (free(buffer), save);
}

char	*extract_line_reload(char **save, char *newL_ptr)
{
	char	*result;
	char	*tmp;

	if (!newL_ptr)
	{
		if (!*save)
			return (NULL);
		result = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (result);
	}
	result = ft_strndup(*save, newL_ptr - *save + 1);
	if (!result)
		return (NULL);
	tmp = *save;
	*save = ft_strdup(newL_ptr + 1);
	if (!*save)
		return (NULL);
	free(tmp);
	return (result);
}

char	*check_newline(char *str)
{
	char	*ptr;

	ptr = str;
	if (!str)
		return (NULL);
	while (*ptr != '\n' && *ptr != '\0')
		ptr++;
	if (*ptr == '\0')
		return (NULL);
	else
		return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, len + 1);
	return (s);
}
