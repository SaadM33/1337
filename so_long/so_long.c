/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:12:51 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/27 20:14:39 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
