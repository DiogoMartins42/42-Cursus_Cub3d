/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:40 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/06 17:14:34 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return(0);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->win.x = 1280;
	data->win.y = 1024;
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
			printf("\n\033[1;32mMap is VALID!\033[0m\n");
			init_game(data);
			while(1);
		}
		cleanup_map(map);
	}
	else
		printf("Error\n\033[1;31mNumber of Arguments is INVALID!\033[0m\n");
}
