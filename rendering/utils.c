/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:16:51 by natallia          #+#    #+#             */
/*   Updated: 2024/12/15 13:07:23 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.space);
	mlx_destroy_image(map->mlx, map->img.wall);
	mlx_destroy_image(map->mlx, map->img.exit);
	mlx_destroy_image(map->mlx, map->img.collectible);
	mlx_destroy_image(map->mlx, map->img.player);
}

int	close_game(t_map *map)
{
	destroy_images(map);
	mlx_destroy_window(map->mlx, map->wnd);
	free_double_array(map->array);
	free_double_array(map->copy);
	exit(EXIT_SUCCESS);
	return (0);
}

void	you_win(t_map *map)
{
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd,
		(map->x / 2) * IMG_PXL, (map->y / 2) * IMG_PXL,0xFFFA9E, "YOU WON!");
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		return (close_game(map));
	else if (keycode == RIGHT)
		move_right(map);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == UP)
		move_up(map);
	else if (keycode == DOWN)
		move_down(map);
	return (0);
}

void	print_moves(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
