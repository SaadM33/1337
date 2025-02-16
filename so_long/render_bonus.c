/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:41:08 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/16 16:30:44 by sel-maaq         ###   ########.fr       */
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

void	load_frames_col(t_game *game)
{
	int (w), (h);
	game->frames_coll[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/col00.xpm", &w, &h);
	game->frames_coll[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/col01.xpm", &w, &h);
	game->frames_coll[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/col02.xpm", &w, &h);
	game->frames_coll[3] = mlx_xpm_file_to_image(game->mlx,
			"assets/col03.xpm", &w, &h);
	game->frames_coll[4] = mlx_xpm_file_to_image(game->mlx,
			"assets/col04.xpm", &w, &h);
	game->frames_coll[5] = mlx_xpm_file_to_image(game->mlx,
			"assets/col05.xpm", &w, &h);
	game->frames_coll[6] = mlx_xpm_file_to_image(game->mlx,
			"assets/col06.xpm", &w, &h);
}

void	load_images(t_game *game)
{
	int (w), (h);
	load_frames_col(game);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player2.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall2.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit2.xpm", &w, &h);
	game->img_mid_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_player2.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor2.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy.xpm", &w, &h);
	game->img_win = mlx_xpm_file_to_image(game->mlx,
			"assets/win_msg.xpm", &w, &h);
	game->img_lose = mlx_xpm_file_to_image(game->mlx,
			"assets/lose_msg.xpm", &w, &h);
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
		map->width / 2 * TILE_SIZE - 25, 25, 16247616, "TOTAL MOVES : ");
	mlx_string_put(game->mlx, game->win,
		map->width / 2 * TILE_SIZE + 60, 25, 16777215, tmp);
	free(tmp);
	tmp = ft_itoa(game->map->collectibles - game->collected);
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE - 25,
		map->height * TILE_SIZE - 25, 16247616, "COINS NEEDED : ");
	mlx_string_put(game->mlx, game->win, map->width / 2 * TILE_SIZE + 85,
		map->height * TILE_SIZE - 25, 16777215, tmp);
	free(tmp);
}
