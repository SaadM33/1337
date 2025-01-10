
#include "so_long.h"

int main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		j;
	char **map;

	int fd = open(argv[1], O_RDONLY);
	while (line = get_next_line(fd))
	{
		ft_putstr_fd(line, 1);
	}
}
