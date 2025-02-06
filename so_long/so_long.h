/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:35 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/01/04 22:14:35 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>



typedef struct s_map
{
	char    **grid;
	int     width;
	int     height;
	int     collectibles;
	int     exit;
	int     player;
	int     player_x;
	int     player_y;
}   t_map;

typedef struct s_game
{
	void    *mlx;
	void    *win;
	t_map   *map;
	void    *img_wall;
	void    *img_player;
	void    *img_collect;
	void    *img_exit;
	void    *img_floor;
	void	*img_mid_exit;
	int     moves;
	int     collected;
}   t_game;

// Map parsing
int		parse_map(t_map *map, char *filename);
void	validate_map(t_map *map, char *filename);
void	validate_rectangular(t_map *map, char *filename);
void	validate_elements(t_map *map);
void	validate_walls(t_map *map);
void	validate_path(t_map *map);

// helper functions
void	flood_fill(char **grid, int x, int y, t_map *map);
char	**copy_map(t_map *map);
void	fill_player_pos(t_map *map);
char	*cpy_no_nl(char *str);
void 	print_map(char **grid);
// Game initialization
void	init_game(t_game *game, t_map *map);
void	load_images(t_game *game, t_map *map);
void	render_map(t_game *game, int y, int x);

// Game logic
int     handle_key(int keycode, t_game *game);
void    move_player(t_game *game, t_map *map, int new_x, int new_y);

// Cleanup
void	free_map(char **map);
int		close_window(t_game *game);
void	handle_error(t_map *map, char *str, int fd);


#endif
