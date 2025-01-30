/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:12:51 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/29 18:52:36 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{	
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("provide map file", 2);
		return (1);
	}
	if (parse_map(&map, argv[1]) == 0)
		return (1);
	validate_map(&map, argv[1]);
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.width * TILE_SIZE, map.height * TILE_SIZE, "if u see this ur gay");
	int i = 0, j = 0;
	game.img_wall =  mlx_xpm_file_to_image(game.mlx, "assets/lava.xpm", &i, &j);
	game.img_floor =  mlx_xpm_file_to_image(game.mlx, "assets/rock.xpm", &i, &j);
	mlx_put_image_to_window(game.mlx, game.win, game.img_wall, 64, 64);
	mlx_put_image_to_window(game.mlx, game.win, game.img_floor, 64, 128);
	mlx_put_image_to_window(game.mlx, game.win, game.img_floor, 64, 64 * 3);
	mlx_put_image_to_window(game.mlx, game.win, game.img_floor, 64, 64 * 4);
	mlx_put_image_to_window(game.mlx, game.win, game.img_floor, 64, 64 * 5);
	mlx_put_image_to_window(game.mlx, game.win, game.img_wall, 0, 64 * 3);
	mlx_put_image_to_window(game.mlx, game.win, game.img_wall, 0, 64 * 4);
	mlx_put_image_to_window(game.mlx, game.win, game.img_wall, 0, 64 * 5);
	mlx_loop(game.mlx);
	free_map(map.grid);
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
