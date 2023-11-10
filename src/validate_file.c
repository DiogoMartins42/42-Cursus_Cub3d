/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:48 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/10 20:46:25 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (true);
	return (false);
}

char	*save_path(char *line, char *trim)
{
	char	*result;
	char	*str;
	int		i;

	str = ft_strtrim(line, trim);
	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
	{
		result = ft_strtrim(str, "\n");
		free(str);
		return (result);
	}
	return (str);
}

bool	add_elements(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO ./", 5))
		map->NO = save_path(line, "NO ./");
	else if (ft_strnstr(line, "SO ./", 5))
		map->SO = save_path(line, "SO ./");
	else if (ft_strnstr(line, "WE ./", 5))
		map->WE = save_path(line, "WE ./");
	else if (ft_strnstr(line, "EA ./", 5))
		map->EA = save_path(line, "EA ./");
	else if (ft_strnstr(line, "F ", 2))
		map->floor_color = save_rgb(ft_strtrim(line, "F "));
	else if (ft_strnstr(line, "C ", 2))
		map->ceiling_color = save_rgb(ft_strtrim(line, "C "));
	else
		return (false);
	return (true);
}

bool	read_file(int fd, t_map *map, char *map_file)
{
	char	*line;
	bool	map_valid;
	int		line_index;

	map_valid = false;
	line_index = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!add_elements(map, line))
		{
			if (check_map_start(line))
			{
				map->map_start = line_index;
				return (validate_map(fd, map, line, map_file));
			}
			if (check_invalid_line(line))
			{
				// leak here
				printf("Error\n\033[1;31mThe file contains invalid elements"
					"\033[0m\n");
				free(line);
				close(fd);
				return (false);
			}
		}
		line_index++;
		free(line);
	}
	close(fd);
	return (map_valid);
}

bool	validate_file(char *map_file, t_map *map)
{
	int		fd;

	fd = check_file_type(map_file);
	if (fd == -1)
		return (false);
	return (read_file(fd, map, map_file));
}
