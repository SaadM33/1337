/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:18:42 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/03 14:42:25 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(t_map *map, char *filename)
{
	validate_rectangular(map, filename);
	validate_elements(map);
	validate_walls(map);
	validate_path(map);
}

void	validate_rectangular(t_map *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;
	char	*last_line;

	i = 0;
	while (map->grid[i])
		if ((size_t)map->width != ft_strlen(map->grid[i++]))
			handle_error(map, "map not rectangular", 0);
	fd = open(filename, O_RDONLY);
	last_line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(last_line);
		last_line = line;
		line = get_next_line(fd);
	}
	if (last_line && last_line[ft_strlen(last_line) - 1] == '\n')
	{
		free(last_line);
		handle_error(map, "extra newline at end of map", 0);
	}
	free(last_line);
	close(fd);
}

void	validate_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_strchr("01CEP", map->grid[i][j]) == NULL)
				handle_error(map, "map has invalid elements", 0);
			if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] == 'P')
				map->player++;
			else if (map->grid[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->collectibles == 0 || map->player == 0 || map->player > 1
		|| map->exit == 0 || map->exit > 1)
		handle_error(map, "map has incorrect amount of an element", 0);
}

void	validate_walls(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	grid = map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != '1' && (i == 0 || i == map->height - 1
				|| j == 0 || j == map->width - 1))
				handle_error(map, "map is not surrounded by walls", 0);
			j++;
		}
		i++;
	}
}

void	validate_path(t_map *map)
{
	char	**cpy_map;
	int		colle;
	int		exit;

	cpy_map = copy_map(map);
	fill_player_pos(map);
	colle = map->collectibles;
	exit = map->exit;
	flood_fill(cpy_map, map->player_x, map->player_y, map);
	if (map->collectibles > 0 || map->exit > 0)
	{
		free_map(cpy_map);
		handle_error(map, "Not all collectibles or exit are reachable", 0);
	}
	map->collectibles = colle;
	map->exit = exit;
	free_map(cpy_map);
}
