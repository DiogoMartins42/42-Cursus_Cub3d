/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:47:14 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/02 20:06:06 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*void	add_elements(t_map *map, char *line)
{

}*/

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
	//	add_elements(map, line);
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
