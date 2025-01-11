
#include "so_long.h"

int main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		j;
	char **map;

	int fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{

		line = get_next_line(fd);
	}
	ft_putnbr_fd(argc, 1);
}

void	parse_map()
{
	char **map;

	map = init_map(map);
}


init_map()
{
	
}