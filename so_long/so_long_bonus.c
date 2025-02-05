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

#include "so_long_bonus.h"
# include "minilibx-linux/mlx.h"

void print_map(t_map *map)
{
	char	**grid;
	int 	i = 0;
	int		j = 0;

	grid = map->grid;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			printf("%c", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("y pos: %d\n", map->player_y);
	printf("x pos: %d\n", map->player_x);
	printf("\n");
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
