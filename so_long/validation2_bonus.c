/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:15:40 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/07 10:50:49 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P' || map->grid[i][j] == 'e')
			{
				map->player_x = j;
				map->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| grid[y][x] == '1' || grid[y][x] == 'V' || grid[y][x] == 'K')
		return ;
	if (grid[y][x] == 'C')
		map->collectibles--;
	if (grid[y][x] == 'E')
		map->exit--;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
