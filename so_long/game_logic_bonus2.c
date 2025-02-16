/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:13:15 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/16 17:48:10 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_victory(t_game *game, t_map *map)
{
	system("pkill paplay");
	play_sound("assets/win.wav");
	mlx_put_image_to_window(game->mlx, game->win, game->img_win,
		map->width * TILE_SIZE / 2 - 208,
		map->height * TILE_SIZE / 2 - 186);
	mlx_do_sync(game->mlx);
	sleep(2);
	close_window(game);
}

void	handle_game_over(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			put_image(game, game->img_enemy, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_lose,
		map->width * TILE_SIZE / 2 - 225,
		map->height * TILE_SIZE / 2 - 170);
	mlx_do_sync(game->mlx);
	system("pkill paplay");
	play_sound("assets/lose.wav");
	sleep(4);
	close_window(game);
}

void	update_player_position(t_game *game, t_map *map, int new_x, int new_y)
{
	if (map->grid[new_y][new_x] == 'C')
	{
		game->collected++;
		play_sound("assets/pickup_sound.wav");
	}
	if (map->grid[map->player_y][map->player_x] == 'e')
		map->grid[map->player_y][map->player_x] = 'E';
	else
		map->grid[map->player_y][map->player_x] = '0';
	map->grid[new_y][new_x] = 'P';
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	free_frames_col(t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(game->mlx, game->frames_coll[i]);
		i++;
	}
}
