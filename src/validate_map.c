/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:25 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/06 20:48:16 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*char	**save_map(char *map_file, t_map *map)
{
	int		fd;
	char	**map_array;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	map_array = malloc(map->height * sizeof(char *));
	if (!map_array)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_array[i] = line;
		i++;
	}
	close(fd);
	return (map_array);
}*/

bool	validate_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == ' '|| line[i] == '\n')
			i++;
		else
			return (false);
	}
	return (true);
}

int	check_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line [i - 1] != '\n')
		return (i);
	return (i - 1);
}

bool	read_map(int fd, t_map *map, char *line)
{
	int		width;

	if (!line)
		return (false);
	while (1)
	{
		if (!validate_characters(line))
		{
			printf("Error\n\033[1;31mThe map contains invalid elements"
				   "\033[0m\n");
			return (false);
		}
		width = check_width(line);
		if (width > map->width)
			map->width = width;
		map->height++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
	}
	printf("Map width: %i\n", map->width);
	printf("Map height: %i\n", map->height);
	return (true);
}

bool	validate_map(int fd, t_map *map, char *line)
{
	//char	**map_array;

	if (read_map(fd, map, line) == false)
		return (false);
	//map_array = save_map(map_file, map);
	//map->map_array = map_array;
	return (true);
}