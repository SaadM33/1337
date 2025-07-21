/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:19:33 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:52 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_ln(char *buffer)
{
	char	*tmp;
	char	*line;

	if (buffer == NULL)
		return (NULL);
	tmp = ft_strchr(buffer, '\n');
	if (tmp != NULL)
		line = ft_substr(buffer, 0, tmp - buffer + 1);
	else
		line = ft_strdup(buffer);
	return (line);
}

static char	*update_storage(char *storage)
{
	char			*tmp;
	unsigned int	start;

	if (storage == NULL)
		return (NULL);
	tmp = ft_strchr(storage, '\n');
	start = tmp - storage + 1;
	tmp = ft_substr(storage, start, ft_strlen(storage) - start);
	ft_free(storage);
	return (tmp);
}

static char	*new_line(char *line, int fd)
{
	char	*buffer;
	char	*tmp;
	ssize_t	i;

	buffer = ft_calloc((unsigned long)BUFFER_SIZE + 1, 1);
	if (line == NULL)
		line = ft_calloc(1, 1);
	if (buffer == NULL || line == NULL)
		return (ft_free(buffer), ft_free(line), NULL);
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (i == 0 && line[0] == '\0')
			return (ft_free(buffer), ft_free(line), NULL);
		tmp = ft_strjoin(line, buffer);
		ft_free(line);
		line = tmp;
		if (i == 0 || line == NULL || ft_strchr(line, '\n'))
			return (ft_free(buffer), line);
	}
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || fd >= 1024)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (ft_free(storage[fd]), NULL);
	if (storage[fd] != NULL)
	{
		line = check_ln(storage[fd]);
		if (line == NULL)
			return (ft_free(storage[fd]), NULL);
	}
	if (!ft_strchr(line, '\n'))
	{
		ft_free(storage[fd]);
		storage[fd] = new_line(line, fd);
		line = check_ln(storage[fd]);
	}
	storage[fd] = update_storage(storage[fd]);
	if (storage[fd] == NULL || line == NULL)
		return (ft_free(storage[fd]), ft_free(line), NULL);
	return (line);
}
