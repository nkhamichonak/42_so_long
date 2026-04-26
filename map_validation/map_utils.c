/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:40:59 by natallia          #+#    #+#             */
/*   Updated: 2026/04/26 12:44:30 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialise_map(t_map *map, char *filename)
{
	map->name = filename;
	map->array = NULL;
	map->copy = NULL;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->x = 0;
	map->y = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->moves = 0;
	map->mlx = NULL;
	map->wnd = NULL;
}

void	generate_array(t_map *map)
{
	int		fd;
	char	*temp;
	char	*long_temp;

	long_temp = NULL;
	fd = open(map->name, O_RDONLY);
	if (fd == -1)
		error_exit("Map file: ", strerror(errno), map);
	while (true)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		long_temp = ft_strjoin_free(long_temp, temp);
		free(temp);
		if (long_temp == NULL)
			error_exit("Map array: ", ERR_MALLOC, map);
	}
	close(fd);
	map->array = ft_split(long_temp, '\n');
	map->copy = ft_split(long_temp, '\n');
	free(long_temp);
	if (map->array == NULL || map->copy == NULL)
		error_exit("Map array: ", ERR_MALLOC, map);
	while (map->array[map->y])
		map->y++;
}

void	get_player_position(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->array[y][x])
		{
			if (map->array[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

bool	is_valid_tile(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->x || y < 0 || y >= map->y)
		return (false);
	if (map->copy[y][x] == 'C' || map->copy[y][x] == 'E' || map->copy[y][x] == '0')
		return (true);
	return (false);
}


