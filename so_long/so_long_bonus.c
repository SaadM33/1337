/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:59:57 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/03/12 16:03:04 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

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
	load_images(&game);
	play_sound("assets/snore.wav");
	render_map(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, animate_coll, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	play_sound(const char *sound_file)
{
	char	*command;
	char	*tmp;

	tmp = ft_strjoin("paplay ", sound_file);
	command = ft_strjoin(tmp, " &");
	free(tmp);
	system(command);
	free(command);
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
