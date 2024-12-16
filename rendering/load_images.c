/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:02:21 by natallia          #+#    #+#             */
/*   Updated: 2024/12/15 12:14:28 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_tile(t_map *map, int x, int y)
{
	int		pixel_x;
	int		pixel_y;

	pixel_x = x * IMG_PXL;
	pixel_y = y * IMG_PXL;
	mlx_put_image_to_window(map->mlx, map->wnd,
		map->img.space, pixel_x, pixel_y);
	if (map->array[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.wall, pixel_x, pixel_y);
	else if (map->array[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.exit, pixel_x, pixel_y);
	else if (map->array[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.collectible, pixel_x, pixel_y);
	else if (map->array[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player, pixel_x, pixel_y);
}

static void	display_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->array[y][x])
		{
			display_tile(map, x, y);
			x++;
		}
		y++;
	}
}

static void	file_to_image(t_map *map)
{
	int		width;
	int		height;

	map->img.space = mlx_xpm_file_to_image(map->mlx,
		"assets/space.xpm", &width, &height);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
		"assets/wall.xpm", &width, &height);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
		"assets/exit.xpm", &width, &height);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
		"assets/collectible.xpm", &width, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx,
		"assets/player.xpm", &width, &height);
}

void	load_images(t_map *map)
{
	file_to_image(map);
	display_map(map);
}
