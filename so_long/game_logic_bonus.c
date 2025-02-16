/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:24:49 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/16 17:21:11 by sel-maaq         ###   ########.fr       */
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
		return (play_sound("assets/wall.wav"));
	if (map->grid[new_y][new_x] == 'K')
	{
		handle_game_over(game, map);
		return ;
	}
	if (map->grid[new_y][new_x] == 'E')
	{
		map->grid[new_y][new_x] = 'e';
		map->grid[map->player_y][map->player_x] = '0';
		if (game->collected == map->collectibles)
		{
			handle_victory(game, map);
			return ;
		}
	}
	else
	{
		update_player_position(game, map, new_x, new_y);
	}
	fill_player_pos(map);
	render_map(game, 0, 0);
	game->moves++;
}

int	animate_coll(t_game *game)
{
	static int	frame = 0;
	char		**grid;

	int (i), (j), (counter);
	grid = game->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				put_image(game, game->frames_coll[frame], j, i);
			j++;
		}
		i++;
	}
	counter = 0;
	while (counter < 7000000)
		counter++;
	frame = (frame + 1) % 7;
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map->grid);
	free_frames_col(game);
	mlx_destroy_image(game->mlx, game->img_mid_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_image(game->mlx, game->img_lose);
	mlx_destroy_image(game->mlx, game->img_win);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	system("pkill paplay");
	exit(0);
}
