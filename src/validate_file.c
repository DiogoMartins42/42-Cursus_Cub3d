/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:48 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/11 16:52:58 by dreis-ma         ###   ########.fr       */
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

bool	read_file(int fd, t_map *map)
{
	char	*line;
	bool	loop;

	loop = true;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (loop && !add_elements(map, line))
		{
			if (check_map_start(line))
				return (read_map(fd, map, line));
			if (check_invalid_line(line))
			{
				loop = false;
				printf("Error\n\033[1;31mThe file contains invalid elements"
					   "\033[0m\n");
			}
		}
		map->map_start++;
		free(line);
	}
	if (loop)
		printf("Error\n\033[1;31mThe file doesn't contain a map \033[0m\n");
	return (false);
}

bool	validate_file(char *map_file, t_map *map)
{
	int		fd;
	bool	result;

	fd = check_file_type(map_file);
	if (fd == -1)
		return (false);
	map->map_file = map_file;
	result = read_file(fd, map);
	close(fd);
	if (result)
		result = validate_map(fd, map);
	return (result);
}
