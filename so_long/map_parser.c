#include "so_long.h"

static int init_map(t_map *map, char *filename)
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
	if (height == 0)
		return (close(fd), 0);
	map->height = height;
	map->grid = malloc(sizeof(char *) * (height + 1));
	if (!map->grid)
		handle_error(map, "error in malloc");
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
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
    		line[ft_strlen(line) - 1] = '\0';
		map->grid[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		line = get_next_line(fd);
		i++;
	}
	map->grid[i] = NULL;
	return (close(fd), 1);
}

void	handle_error(t_map *map, char *str)
{
	free_map(map->grid);
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(str, 2);
	exit(0);
}
