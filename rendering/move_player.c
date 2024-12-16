/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:34 by natallia          #+#    #+#             */
/*   Updated: 2024/12/15 13:10:07 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_interactions(t_map *map, int new_x, int new_y)
{
	if (map->array[new_y][new_x] == 'E' && map->c == 0)
		you_win(map);
	if (map->array[new_y][new_x] == 'C')
		map->c--;
}

void	move_up(t_map *map)
{
	int		x;
	int		y;

	x = map->player_x;
	y = map->player_y;
	if (map->array[y - 1][x] != '1')
	{
		handle_interactions(map, x, y - 1);
		if (map->array[y - 1][x] == 'E')
			return ;
		map->array[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.space, x * IMG_PXL, y * IMG_PXL);
		y--;
		map->moves++;
		map->array[y][x] = 'P';
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.space,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		print_moves(map);
		map->player_y = y;
	}
}

void	move_down(t_map *map)
{
	int		x;
	int		y;

	x = map->player_x;
	y = map->player_y;
	if (map->array[y + 1][x] != '1')
	{
		handle_interactions(map, x, y + 1);
		if (map->array[y + 1][x] == 'E')
			return ;
		map->array[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.space, x * IMG_PXL, y * IMG_PXL);
		y++;
		map->moves++;
		map->array[y][x] = 'P';
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.space,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		print_moves(map);
		map->player_y = y;
	}
}

void	move_left(t_map *map)
{
	int		x;
	int		y;

	x = map->player_x;
	y = map->player_y;
	if (map->array[y][x - 1] != '1')
	{
		handle_interactions(map, x - 1, y);
		if (map->array[y][x - 1] == 'E')
			return ;
		map->array[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.space, x * IMG_PXL, y * IMG_PXL);
		x--;
		map->moves++;
		map->array[y][x] = 'P';
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.space,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		print_moves(map);
		map->player_x = x;
	}
}
void	move_right(t_map *map)
{
	int		x;
	int		y;

	x = map->player_x;
	y = map->player_y;
	if (map->array[y][x + 1] != '1')
	{
		handle_interactions(map, x + 1, y);
		if (map->array[y][x + 1] == 'E')
			return ;
		map->array[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.space, x * IMG_PXL, y * IMG_PXL);
		x++;
		map->moves++;
		map->array[y][x] = 'P';
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.space,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		print_moves(map);
		map->player_x = x;
	}
}
