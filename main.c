/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:11 by natallia          #+#    #+#             */
/*   Updated: 2026/04/26 12:44:30 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (argc != 2)
		error_exit("Input: ", ERR_ARG, &map);
	initialise_map(&map, argv[1]);
	check_map_is_valid(&map);
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx,
		map.x * IMG_PXL, map.y * IMG_PXL, "so_long");
	load_images(&map);
	mlx_key_hook(map.wnd, key_hook, &map);
	mlx_hook(map.wnd, 17, 0, close_game, &map);
	mlx_loop(map.mlx);
}
