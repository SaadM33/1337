#include "so_long.h"

void	validate_map(t_map *map)
{
	validate_rectangular(map);
	validate_elements(map);
	// validate_walls(map);
	// validate_path(map);
	
}

void	validate_rectangular(t_map *map)
{
	int i;

	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != map->width)
			handle_error(map, "map not rectangular");
		i++;
	}
}

void	validate_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		if (ft_strchr("01CEP", map->grid[i]) == NULL)
			handle_error(map, "map has invalid elements");
		if (map->grid == 'C')
			map->collectibles++;
		else if (map->grid[i] == 'P')
			map->player++;
		else if (map->grid[i] == 'E')
			map->exit++;
		i++;
	}
	if (map->collectibles == 0 || map->player == 0 || map->player > 1
		|| map->exit == 0 || map->exit > 1)
		handle_error(map, "map has too many of an element");
}