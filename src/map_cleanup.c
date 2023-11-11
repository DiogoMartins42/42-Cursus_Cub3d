/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:00 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/11 16:10:55 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cleanup_map_array(t_map *map)
{
	int	i;

	i = 0;
	if (!map->map_array)
		return ;
	while (i < map->height)
	{
		free (map->map_array[i]);
		i++;
	}
	free(map->map_array);
}

void	cleanup_map(t_map *map)
{
	if (map->NO)
		free(map->NO);
	if (map->SO)
		free(map->SO);
	if (map->WE)
		free(map->WE);
	if (map->EA)
		free(map->EA);
	if (map->ceiling_color)
		free(map->ceiling_color);
	if (map->floor_color)
		free(map->floor_color);
	cleanup_map_array(map);
	free(map);
}
