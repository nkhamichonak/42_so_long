/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:31:53 by natallia          #+#    #+#             */
/*   Updated: 2024/12/13 13:50:05 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void		enqueue(t_tile *queue, t_tile tile, int *back)
{
	queue[*back] = tile;
	(*back)++;
}

static t_tile	dequeue(t_tile *queue, int *front)
{
	t_tile		temp;

	temp = queue[*front];
	(*front)++;
	return (temp);
}

static void	enqueue_neighbours(t_tile *queue, t_tile curr, int *back, t_map *m)
{
	int		i;
	t_tile	neighbour[4];

	i = 0;
	neighbour[0] = (t_tile){curr.x + 1, curr.y};
	neighbour[1] = (t_tile){curr.x - 1, curr.y};
	neighbour[2] = (t_tile){curr.x, curr.y + 1};
	neighbour[3] = (t_tile){curr.x, curr.y - 1};
	while (i < 4)
	{
		if (is_valid_tile(neighbour[i].x, neighbour[i].y, m))
		{
			m->copy[neighbour[i].y][neighbour[i].x] = '1';
			enqueue(queue, neighbour[i], back);
		}
		i++;
	}
}

void	check_valid_path(t_map *map, t_map check)
{
	int		front;
	int		back;
	t_tile	*queue;
	t_tile	current;

	front = 0;
	back = 0;
	queue = malloc((map->x * map->y) * sizeof(t_tile));
	if (queue == NULL)
		error_exit("Path finder: ", ERR_MALLOC, map);
	get_player_position(map);
	enqueue(queue, (t_tile){map->player_x, map->player_y}, &back);
	while (front < back)
	{
		current = dequeue(queue, &front);
		if (map->array[current.y][current.x] == 'C')
			check.c--;
		if (map->array[current.y][current.x] == 'E')
			check.e--;
		map->copy[current.y][current.x] = '1';
		enqueue_neighbours(queue, current, &back, map);
	}
	free(queue);
	if (check.e != 0 || check.c != 0)
		error_exit("Path finder: ", ERR_PATH, map);
}
