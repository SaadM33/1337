#include "so_long.h"

static int init_map(t_map *map, char *filename)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (height == 0)
		return (0);
	map->height = height;
	map->grid = malloc(sizeof(char *) * (height + 1));
	if (!map->grid)
		return (0);
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	return (close(fd), 1);
}

int parse_map(t_map *map, char *filename)
{
	int     fd;
	int		i;
	char    *line;

	if (!init_map(map, filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
    		line[ft_strlen(line) - 1] = '\0';
		map->grid[i++] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	close(fd);
	return (1);
}

// static int validate_chars(t_map *map)
// {
// 	int i;
// 	int j;
// 	i = -1;
// 	while (++i < map->height)
// 	{
// 		j = -1;
// 		while (map->grid[i][++j])
// 		{
// 			if (map->grid[i][j] == 'P')
// 			{
// 				map->player++;
// 				map->player_x = j;
// 				map->player_y = i;
// 			}
// 			else if (map->grid[i][j] == 'E')
// 				map->exit++;
// 			else if (map->grid[i][j] == 'C')
// 				map->collectibles++;
// 			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1')
// 				return (0);
// 		}
// 	}
// 	return (map->player == 1 && map->exit == 1 && map->collectibles > 0);
// }

// int validate_map(t_map *map)
// {
// 	int i;
// 	int j;
// 	i = -1;
// 	while (++i < map->height)
// 	{
// 		j = -1;
// 		while (++j < map->width)
// 		{
// 			if (i == 0 || i == map->height - 1 || 
// 				j == 0 || j == map->width - 1)
// 			{
// 				if (map->grid[i][j] != '1')
// 					return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }
