/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:36 by natallia          #+#    #+#             */
/*   Updated: 2024/12/15 21:20:47 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# ifdef __APPLE__
#  include "mlx_mac/mlx.h"
# else
#  include "mlx_linux/mlx.h"
# endif
# include <fcntl.h>
# include <string.h>
# include <errno.h>
#include <sys/time.h>

# define ERR_ARG "Invalid argument count."
# define ERR_EXT "Invalid file extension."
# define ERR_MALLOC "Failed to allocate memory."
# define ERR_REC "Not rectangular."
# define ERR_WALL "Continuous wall not found."
# define ERR_CHAR "Invalid character found."
# define ERR_COUNT "Invalid player, collectible, or exit count."
# define ERR_PATH "Invalid path."

# define IMG_PXL	64
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define ESC		53

typedef struct s_img
{
	void	*space;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*player;
}	t_img;

typedef struct	s_map
{
	char		*name;
	char		**array;
	char		**copy;
	int			c;
	int			e;
	int			p;
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			moves;
	int			won;
	void		*mlx;
	void		*wnd;
	int			frame;
	double		last_update;
	t_img		img;
}	t_map;

typedef struct s_tile
{
	int		x;
	int		y;
}	t_tile;

// map validation
void	initialise_map(t_map *map, char *filename);
void	generate_array(t_map *map);
bool	check_map_is_valid(t_map *map);
void	check_valid_path(t_map *map, t_map map_copy);
void	get_player_position(t_map *map);
bool	is_valid_tile(int x, int y, t_map *map);

// utils
void	error_exit(char *context, char *error_msg, t_map *map);
void	free_double_array(char **str);

// rendering
void	load_images(t_map *map);

int		key_hook(int keycode, t_map *map);
void	you_win(t_map *map);
int		close_game(t_map *map);
void	print_moves(t_map *map);


void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

int	update_animation(t_map *map);

#endif
