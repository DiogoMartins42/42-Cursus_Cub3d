/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:16 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/16 13:55:36 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement_a_press(t_data *data, double move_spd)
{
	int	x;
	int	y;

	x = (int)(data->ray.pos_x - data->ray.plane_x * move_spd);
	y = (int) data->ray.pos_y;
	printf("a");
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_x -= data->ray.plane_x * move_spd;
	x = (int) data->ray.pos_x;
	y = (int)(data->ray.pos_y - data->ray.plane_y * move_spd);
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_y -= data->ray.plane_y * move_spd;
}

void	movement_d_press(t_data *data, double move_spd)
{
	int	x;
	int	y;

	x = (int)(data->ray.pos_x + data->ray.plane_x * move_spd);
	y = (int) data->ray.pos_y;
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_x += data->ray.plane_x * move_spd;
	x = (int) data->ray.pos_x;
	y = (int)(data->ray.pos_y + data->ray.plane_y * move_spd);
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_y += data->ray.plane_y * move_spd;
}

void	movement_s_press(t_data *data, double move_spd)
{
	int	x;
	int	y;

	x = (int)(data->ray.pos_x - data->ray.dir_x * move_spd);
	y = (int) data->ray.pos_y;
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_x -= data->ray.dir_x * move_spd;
	x = (int) data->ray.pos_x;
	y = (int)(data->ray.pos_y - data->ray.dir_y * move_spd);
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_y -= data->ray.dir_y * move_spd;
}

void	movement_w_press(t_data *data, double move_spd)
{
	int	x;
	int	y;

	x = (int)(data->ray.pos_x + data->ray.dir_x * move_spd);
	y = (int) data->ray.pos_y;
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_x += data->ray.dir_x * move_spd;
	x = (int) data->ray.pos_x;
	y = (int)(data->ray.pos_y + data->ray.dir_y * move_spd);
	if (data->map->map_array[y][x] == '0')
		data->ray.pos_y += data->ray.dir_y * move_spd;
}
