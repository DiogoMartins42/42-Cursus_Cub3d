/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:40 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/10 20:36:37 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->win.x = 1280;
	data->win.y = 1024;
	data->map = NULL;
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		setup_map(map);
		data = init_data();
		if (validate_file(av[1], map))
		{
			data->map = map;
			printf("\n\033[1;32mMap is VALID!\033[0m\n");
			printf("%s", data->map->map_array[0]);
			printf("Ceiling_color: %i - %i - %i\n", data->map->ceiling_color[0],
				data->map->ceiling_color[1], data->map->ceiling_color[2]);
			printf("Floor_color: %i - %i - %i\n", data->map->floor_color[0],
				data->map->floor_color[1], data->map->floor_color[2]);
			printf("Player start pos x: %i y: %i direction: %c\n",
				map->p_init_x, map->p_init_y, map->p_init_dir);
			printf("NO texture: %s\n", data->map->NO);
			printf("SO texture: %s\n", data->map->SO);
			printf("WE texture: %s\n", data->map->WE);
			printf("EA texture: %s\n", data->map->EA);
		//	init_game(data);
		//	while(1);
		}
		cleanup_map(map);
		free(data);
	}
	else
		printf("Error\n\033[1;31mNumber of Arguments is INVALID!\033[0m\n");
}
