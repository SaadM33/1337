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
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>

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
int     parse_map(t_map *map, char *filename);
int     validate_map(t_map *map);
int     check_path(t_map *map);

// Game initialization
int     init_game(t_game *game);
int     load_images(t_game *game);

// Game logic
int     handle_key(int keycode, t_game *game);
void    move_player(t_game *game, int new_x, int new_y);

// Cleanup
void    free_map(t_map *map);
int     clean_exit(t_game *game);



#endif
