/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:25 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/11 16:57:11 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_player_pos(char *line, t_map *map, int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			map->p_init_y = j;
			map->p_init_x = i;
			map->p_init_dir = line[i];
			break ;
		}
		i++;
	}
}

char	**save_map(t_map *map, int fd, int i)
{
	char	**map_array;
	char	*line;
	int		j;

	j = 0;
	map_array = malloc(map->height * sizeof(char *));
	if (!map_array)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i >= map->map_start)
		{
			check_player_pos(line, map, j);
			map_array[j] = line;
			j++;
		}
		else
			free(line);
		i++;
	}
	return (map_array);
}

bool	validate_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == ' ' || line[i] == '\n')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	read_map(int fd, t_map *map, char *line)
{
	int		width;
	bool	result;

	result = true;
	if (!line)
		return (false);
	while (1)
	{
		if (result && !validate_characters(line))
		{
			printf("Error\n\033[1;31mThe map contains invalid elements"
				"\033[0m\n");
			result = false;
		}
		width = check_width(line);
		if (width > map->width)
			map->width = width;
		map->height++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	return (result);
}

bool	validate_map(int fd, t_map *map)
{
	fd = open(map->map_file, O_RDONLY);
	map->map_array = save_map(map, fd, 0);
	close(fd);
	if (map->p_init_dir == 0)
	{
		printf("Error\n\033[1;31mThe map doesn't contain a player's start "
			   "position\033[0m\n");
		return (false);
	}
	if (!map->floor_color || !map->ceiling_color)
	{
		printf("Error\n\033[1;31mWrong Floor or Ceiling color\033[0m\n");
		return (false);
	}
	return (true);
}
