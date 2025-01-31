
#include "so_long.h"
# define TILE_SIZE 64
void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	**grid;

	grid = game->map->grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			else if (grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
			else if (grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			else if (grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE, map->height * TILE_SIZE, "AAA game");
	game->map = map;
	game->moves = 0;
	game->collected = 0;   
}

void	load_images(t_game *game, t_map *map)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w, &h);
    game->img_collect = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &w, &h);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w, &h);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	if (!game->img_player)
		handle_error(map, "error loading wall sprite", 0);
	else if (!game->img_player)
		handle_error(map, "error loading player sprite", 0);
	else if (!game->img_collect)
		handle_error(map, "error loading collectible sprite", 0);
	else if (!game->img_exit)
		handle_error(map, "error loading exit sprite", 0);
	else if (!game->img_floor)
		handle_error(map, "error loading floor sprite", 0);
}
