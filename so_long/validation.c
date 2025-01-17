#include "so_long.h"

void	validate_map(t_map *map)
{
	validate_rectangular(map);
	// validate_elements(map);
	// validate_walls(map);
	// validate_path(map);
	
}

void	validate_rectangular(t_map *map)
{
	int i;

    i = 0;
    while (map->grid[i])
    {
        if ((size_t)map->width != ft_strlen(map->grid[i]))
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
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_strchr("01CEP", map->grid[i][j]) == NULL)
				handle_error(map, "map has invalid elements");
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
		handle_error(map, "map has too many of an element");
}
