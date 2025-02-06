/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:51:08 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/06 21:18:13 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			"assets/new_player2.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/new_collectible2.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit2.xpm", &w, &h);
	game->img_mid_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_player2.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor2.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"assets/killer.xpm", &w, &h);
	if (!game->img_player)
		handle_error(map, "error loading wall sprite", 0);
	else if (!game->img_player)
		handle_error(map, "error loading player sprite", 0);
	else if (!game->img_collect)
		handle_error(map, "error loading collectible sprite", 0);
	else if (!game->img_exit)
		handle_error(map, "error loading exit sprite", 0);
	else if (!game->img_mid_exit)
		handle_error(map, "error loading mid exit sprite", 0);
	else if (!game->img_floor)
		handle_error(map, "error loading floor sprite", 0);
	else if (!game->img_enemy)
		handle_error(map, "error loading enemy sprite", 0);
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
			map->width / 2 * TILE_SIZE - 25, 25, 9495366, "TOTAL MOVES : ");
	mlx_string_put(game->mlx, game->win,
			map->width / 2 * TILE_SIZE + 60, 25, 9495366, tmp);
	free(tmp);
	tmp = ft_itoa(game->collected);
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE - 25,
			map->height * TILE_SIZE - 25, 9495366, "TOTAL COLLECTED : ");
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE + 85,
			map->height * TILE_SIZE - 25, 9495366, tmp);
	free(tmp);
}
