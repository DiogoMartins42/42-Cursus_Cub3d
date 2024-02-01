/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:48 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/24 20:10:06 by dreis-ma         ###   ########.fr       */
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

/*char	*save_path(char *line, char *trim)
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
}*/

char	*save_path(char *line, char *trim, char *path, t_map *map)
{
	char	*result;
	char	*str;
	int		i;

	if (path)
	{
		free(path);
		map->duplicated_elements = true;
		return (NULL);
	}
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
		map->no = save_path(line, "NO ./", map->no, map);
	else if (ft_strnstr(line, "SO ./", 5))
		map->so = save_path(line, "SO ./", map->so, map);
	else if (ft_strnstr(line, "WE ./", 5))
		map->we = save_path(line, "WE ./", map->we, map);
	else if (ft_strnstr(line, "EA ./", 5))
		map->ea = save_path(line, "EA ./", map->ea, map);
	else if (ft_strnstr(line, "F ", 2))
	{
		if (!map->floor_color)
			map->floor_color = save_rgb(ft_strtrim(line, "F "));
		else
			map->duplicated_elements = true;
	}
	else if (ft_strnstr(line, "C ", 2))
	{
		if (!map->ceiling_color)
			map->ceiling_color = save_rgb(ft_strtrim(line, "C "));
		else
			map->duplicated_elements = true;
	}
	else
		return (false);
	return (true);
}

bool	read_file(int fd, t_map *map, bool loop, char *line)
{
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
				loop = false;
		}
		else if (loop && (map->duplicated_elements == true))
		{
			printf("Error\n\033[1;31mFile has duplicated elements\033[0m\n");
			loop = false;
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
	char	*line;

	result = true;
	line = NULL;
	fd = check_file_type(map_file);
	if (fd == -1)
		return (false);
	map->map_file = map_file;
	result = read_file(fd, map, result, line);
	close(fd);
	if (result)
		result = validate_map(fd, map);
	return (result);
}
