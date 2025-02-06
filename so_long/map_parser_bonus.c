/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:14:21 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/05 22:40:24 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_empty(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(str, 2);
}

static int	init_map(t_map *map, char *filename)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (close(fd), 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
	if (height == 0)
		return (close(fd), 0);
	map->grid = malloc(sizeof(char *) * (height + 1));
	if (!map->grid)
		handle_error(map, "error in malloc", fd);
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	return (close(fd), 1);
}

int	parse_map(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	*line_pro;

	if (!init_map(map, filename))
		return (handle_empty("empty map or no such file"), 0);
	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_pro = cpy_no_nl(line);
		if (!line_pro)
			handle_error(map, "error in mallocing the copy", fd);
		free(line);
		map->grid[i] = line_pro;
		if (i == 0)
			map->width = ft_strlen(line_pro);
		line = get_next_line(fd);
		i++;
	}
	map->grid[i] = NULL;
	return (close(fd), 1);
}

char	*cpy_no_nl(char *str)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	if (ft_strchr(str, '\n') != NULL)
		res = malloc(len);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	handle_error(t_map *map, char *str, int fd)
{
	free_map(map->grid);
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(str, 2);
	if (fd != 0)
		close(fd);
	exit(0);
}
