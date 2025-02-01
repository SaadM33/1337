#include "so_long.h"

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 100 || keycode == 65363)
		printf("key is right\n");
	else if (keycode == 119 || keycode == 65362)
		printf("key is up\n");
	else if (keycode == 115 || keycode == 65364)
		printf("key is down\n");
	else if (keycode == 97 || keycode == 65361)
		printf("key is left\n");
	else if (keycode == 113)
		printf("key is special\n");
	// move_player(game, 0, 1);
	return (1);
}

// void	move_player(t_game *game, int new_x, int new_y)
// {
// 	game->
// }

int close_window(t_game *game)
{
	free_map(game->map->grid);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_putendl_fd("i quit", 1);
	exit(0);
}