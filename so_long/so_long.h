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
void	find_player(t_map *map);
char	*cpy_no_nl(char *str);

// Game initialization
int     init_game(t_game *game);
int     load_images(t_game *game);

// Game logic
int     handle_key(int keycode, t_game *game);
void    move_player(t_game *game, int new_x, int new_y);

// Cleanup
void    free_map(char **map);
int     clean_exit(t_game *game);
void	handle_error(t_map *map, char *str, int fd);


#endif
