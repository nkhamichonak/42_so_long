/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:19:21 by natallia          #+#    #+#             */
/*   Updated: 2024/12/14 23:20:55 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *context, char *error_msg, t_map *map)
{
	free_double_array(map->copy);
	free_double_array(map->array);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(context, 2);
	ft_putendl_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}

void	free_double_array(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}
