
#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
        return (1);
	if (parse_map(&map, argv[1]) == 0)
		return (1);	
	validate_map(&map);
	free_map(map.grid);
	return (0);		
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

