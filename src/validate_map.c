/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:47:14 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/03 20:06:20 by dreis-ma         ###   ########.fr       */
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
		map->NO = ft_strtrim(line, "SO ./");
	else if (ft_strnstr(line, "WE ./", 5))
		map->NO = ft_strtrim(line, "WE ./");
	else if (ft_strnstr(line, "EA ./", 5))
		map->NO = ft_strtrim(line, "EA ./");
	else if (ft_strnstr(line, "F ", 2))
		map->floor_color = ft_strtrim(line, "F ");
	else if (ft_strnstr(line, "C ", 2))
		map->ceiling_color = ft_strtrim(line, "C ");
	else
		return (false);
	return (true);
}

int	read_map(int fd, t_map *map)
{
	char	*line;
	int		res;
	(void)map;

	res = 1;
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
				break ;
			}
			if (check_invalid_line(line))
			{
				printf("Error\n\033[1;31mThe map contains invalid elements\033[0m\n");
				return (-1);
			}
		}
		/*map->width = check_width(line, map->width);
		if (map->width == 0)
			res = 2;
		if (validate_characters(line) == 0)
			res = 3;
		map->height++;*/
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (res);
}

/*void	setup_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->starting_pos = 0;
	map->exit = 0;
	map->curr_pos_x = 0;
	map->curr_pos_y = 0;
	map->collected_col = 0;
}*/

int	check_open_file(char *map_file)
{
	int	fd;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n\033[1;31mThe file could not be opened\033[0m\n");
		return (-1);
	}
	return (fd);
}

int	check_file_type(char *map_file)
{
	int		i;
	int		j;
	char	*cub;

	i = 0;
	j = 3;
	cub = ".cub";
	while (map_file[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (map_file[i] != cub[j])
		{
			printf("Error\n\033[1;31mMap file type is INVALID!\033[0m\n");
			return (-1);
		}
		j--;
		i--;
	}
	return (check_open_file(map_file));
}

bool	validate_map(char *map_file)
{
	t_map	*map;
	int		fd;

	fd = check_file_type(map_file);
	if (fd == -1)
		return (false);
	map = malloc(sizeof(t_map));
	//setup_map(map);
	read_map(fd, map);
	return (true);
}
