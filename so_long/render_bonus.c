

#include "so_long_bonus.h"

void	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, "sooo_long");
	game->map = map;
	game->moves = 0;
	game->collected = 0;
}

void	load_images(t_game *game, t_map *map)
{
	int (w), (h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
		"assets/wall2.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
		"assets/player2.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
		"assets/collectible2.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
		"assets/exit2.xpm", &w, &h);
	game->img_mid_exit = mlx_xpm_file_to_image(game->mlx,
		"assets/exit_player2.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
		"assets/floor2.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
		"assets/enemy.xpm", &w, &h);
	game->img_lose = mlx_xpm_file_to_image(game->mlx,
		"assets/lose_msg.xpm", &w, &h);
	if (!game->img_wall || !game->img_lose || !game->img_exit
		|| !game->img_enemy || !game->img_collect || !game->img_player
		|| !game->img_mid_exit || !game->img_floor)
		handle_error(map, "error loading a sprite", 0);
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game, int y, int x)
{
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (game->map->grid[y][x] == '0')
				put_image(game, game->img_floor, x, y);
			else if (game->map->grid[y][x] == '1')
				put_image(game, game->img_wall, x, y);
			else if (game->map->grid[y][x] == 'C')
				put_image(game, game->img_collect, x, y);
			else if (game->map->grid[y][x] == 'P')
				put_image(game, game->img_player, x, y);
			else if (game->map->grid[y][x] == 'E')
				put_image(game, game->img_exit, x, y);
			else if (game->map->grid[y][x] == 'e')
				put_image(game, game->img_mid_exit, x, y);
			else if (game->map->grid[y][x] == 'K')
				put_image(game, game->img_enemy, x, y);
			x++;
		}
		y++;
	}
	render_moves(game, game->map);
}

void	render_moves(t_game *game, t_map *map)
{
	char	*tmp;

	tmp = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win,
		map->width / 2 * TILE_SIZE - 25, 25, 16777215, "TOTAL MOVES : ");
	mlx_string_put(game->mlx, game->win,
		map->width / 2 * TILE_SIZE + 60, 25, 16777215, tmp);
	free(tmp);
	tmp = ft_itoa(game->map->collectibles - game->collected);
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE - 25,
		map->height * TILE_SIZE - 25, 16777215, "COINS NEEDED : ");
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE + 85,
		map->height * TILE_SIZE - 25, 16777215, tmp);
	free(tmp);
}
