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

int	main(int ac, char **av)
{
	//t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		setup_map(map);
		if (validate_file(av[1], map))
		{
			printf("\n\033[1;32mMap is VALID!\033[0m\n");
			//init_game(data);
		}
		cleanup_map(map);
	}
	else
		printf("Error\n\033[1;31mNumber of Arguments is INVALID!\033[0m\n");
}
