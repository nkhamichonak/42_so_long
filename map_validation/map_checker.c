/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:18:16 by natallia          #+#    #+#             */
/*   Updated: 2024/12/13 13:54:36 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_file(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->name);
	if (len < 4 || ft_strcmp(&map->name[len - 4], ".ber"))
		error_exit("Input: ", ERR_EXT, map);
}

static void	check_rectangular(t_map *map)
{
	int		x;
	int		y;
	int		x_len;

	x = 0;
	y = 0;
	x_len = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (x != x_len)
			error_exit("Map: ", ERR_REC, map);
		y++;
	}
	map->x = x_len;
}

static void	check_walls(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->array[0][x])
	{
		if (map->array[0][x] != '1')
			error_exit("Map: ", ERR_WALL, map);
		if (map->y > 1 && map->array[map->y - 1][x] != '1')
			error_exit("Map: ", ERR_WALL, map);
		x++;
	}
	y = 0;
	while (y < map->y)
	{
		if (map->array[y][0] != '1')
			error_exit("Map: ", ERR_WALL, map);
		if (map->x > 1 && map->array[y][map->x - 1] != '1')
			error_exit("Map: ", ERR_WALL, map);
		y++;
	}
}

static void	check_components(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->array[y][x])
		{
			if (map->array[y][x] == 'C')
				map->c++;
			else if (map->array[y][x] == 'E')
				map->e++;
			else if (map->array[y][x] == 'P')
				map->p++;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				error_exit("Map: ", ERR_CHAR, map);
			x++;
		}
		y++;
	}
		if (map->c < 1 || map->e != 1 || map->p != 1)
			error_exit("Map: ", ERR_COUNT, map);
}

bool	check_map_is_valid(t_map *map)
{
	check_file(map);
	generate_array(map);
	check_rectangular(map);
	check_walls(map);
	check_components(map);
	check_valid_path(map, *map);
	return (true);
}
