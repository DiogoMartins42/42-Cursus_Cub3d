/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:28:39 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/24 19:51:03 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_char(char c)
{
	if (!c)
		return (true);
	if (c == ' ')
		return (false);
	return (true);
}

bool	check_boundaries(int y, int x, t_map *map_s)
{
	if (y <= 0 || y >= (map_s->height - 1) || x <= 0 || x >= (map_s->width - 1))
		return (true);
	return (false);
}

bool	check_surroundings(char **map, int y, int x, t_map *map_s)
{
	if (check_boundaries(y, x, map_s))
		return (false);
	return (check_char(map[y - 1][x - 1]) && check_char(map[y - 1][x]) && \
			check_char(map[y - 1][x + 1]) && check_char(map[y][x - 1]) && \
			check_char(map[y][x + 1]) && check_char(map[y + 1][x - 1]) && \
			check_char(map[y + 1][x]) && check_char(map[y + 1][x + 1]));
}

bool	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_array[y][x] == '0' || map->map_array[y][x] == 'N'
				|| map->map_array[y][x] == 'S' || map->map_array[y][x] == 'E'
				|| map->map_array[y][x] == 'W')
			{
				if (!check_surroundings(map->map_array, y, x, map))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	validate_walls(t_map *map)
{
	if (!check_walls(map))
	{
		printf("Error\n\033[1;31mThe map is not surrounded by walls\033[0m\n");
		return (false);
	}
	return (true);
}
