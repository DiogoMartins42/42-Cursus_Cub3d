/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:48 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/06 17:29:08 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_invalid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}

bool	check_map_start(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (true);
	return (false);
}

bool	add_elements(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO ./", 5))
		map->NO = ft_strtrim(line, "NO ./");
	else if (ft_strnstr(line, "SO ./", 5))
		map->SO = ft_strtrim(line, "SO ./");
	else if (ft_strnstr(line, "WE ./", 5))
		map->WE = ft_strtrim(line, "WE ./");
	else if (ft_strnstr(line, "EA ./", 5))
		map->EA = ft_strtrim(line, "EA ./");
	else if (ft_strnstr(line, "F ", 2))
		map->floor_color = ft_strtrim(line, "F ");
	else if (ft_strnstr(line, "C ", 2))
		map->ceiling_color = ft_strtrim(line, "C ");
	else
		return (false);
	return (true);
}

bool	read_file(int fd, t_map *map, char *map_file)
{
	char	*line;
	bool	map_valid;

	map_valid = false;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!add_elements(map, line))
		{
			if (check_map_start(line))
			{
				printf("MAP STARTS!\n");
				return (validate_map(fd, map, line, map_file));
				//map_valid = validate_map(fd, map, line);
			//	break ;
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
		printf("%s", line);
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
