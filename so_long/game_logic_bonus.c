/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:12:53 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/02/05 19:12:54 by sel-maaq         ###   ########.fr       */
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
		mlx_string_put(game->mlx, game->win, 10, 10, 0, "you got me");
	return (1);
}

void	move_player(t_game *game, t_map *map, int new_x, int new_y)
{
	 // Wrap around the map edges
    if (new_x < 0)
        new_x = map->width - 1; // Move to the right edge
    else if (new_x >= map->width)
        new_x = 0; // Move to the left edge
    if (new_y < 0)
        new_y = map->height - 1;
    else if (new_y >= map->height)
        {new_y = 0;}


	if (map->grid[new_y][new_x] == '1')
		return ;
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
			game->collected++;
		if (map->grid[map->player_y][map->player_x] == 'e')
			map->grid[map->player_y][map->player_x] = 'E';
		else
			map->grid[map->player_y][map->player_x] = '0';
		map->grid[new_y][new_x] = 'P';
	}
	printf("Moves: %d\n", ++game->moves);
	fill_player_pos(map);
	render_map(game, 0, 0);
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
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
