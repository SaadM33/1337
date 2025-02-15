/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:24:49 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/15 14:30:50 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <X11/keysym.h>

int	handle_key(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->map->player_x;
	y = game->map->player_y;
	if (keycode == XK_Escape)
		close_window(game);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, game->map, x - 1, y);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, game->map, x + 1, y);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, game->map, x, y - 1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, game->map, x, y + 1);
	else if (keycode == XK_q)
		play_sound("assets/dry-fart.wav");
	render_map(game, 0, 0);
	return (1);
}

void	move_player(t_game *game, t_map *map, int new_x, int new_y)
{
	if (map->grid[new_y][new_x] == '1')
	{
		play_sound("assets/wall.wav");
		return ;
	}
	else if (map->grid[new_y][new_x] == 'K')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_mid_exit, map->width * TILE_SIZE /2-225, map->height * TILE_SIZE /2-170);
		sleep(3);
		system("pkill paplay");
		play_sound("assets/lose.wav");
		// sleep(1);
		close_window(game);
	}
	if (map->grid[new_y][new_x] == 'E')
	{
		map->grid[new_y][new_x] = 'e';
		map->grid[map->player_y][map->player_x] = '0';
		if (game->collected == map->collectibles)
		{
			render_map(game, 0, 0);
			close_window(game);
		}
	}
	else
	{
		if (map->grid[new_y][new_x] == 'C')
			{game->collected++;play_sound("assets/pickup_sound.wav");}
		if (map->grid[map->player_y][map->player_x] == 'e')
			map->grid[map->player_y][map->player_x] = 'E';
		else
			map->grid[map->player_y][map->player_x] = '0';
		map->grid[new_y][new_x] = 'P';
	}
	fill_player_pos(map);
	game->moves++;
}

int	close_window(t_game *game)
{
	free_map(game->map->grid);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_mid_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_image(game->mlx, game->img_lose);
	mlx_destroy_image(game->mlx, game->img_win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	system("pkill paplay");
	exit(0);
}
