/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:12:51 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/30 20:15:17 by el-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "minilibx-linux/mlx.h"

void	show_pp(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 3, 64*3);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 3, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 3, 64*5);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 4, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 5, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 6, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 7, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 8, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 9, 64*4);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 64 * 10, 64*4);
}


int	main(int argc, char **argv)
{
	t_map	map;
	t_game game;

	if (argc != 2)
	{	
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("provide map file", 2);
		return (1);
	}
	if (parse_map(&map, argv[1]) == 0)
		return (1);
	validate_map(&map, argv[1]);
	init_game(&game, &map);
	load_images(&game, &map);
	// show_pp(&game);
	render_map(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
