/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:27 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/12 15:06:45 by dreis-ma         ###   ########.fr       */
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
