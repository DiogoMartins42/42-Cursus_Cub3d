/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:07:00 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/15 14:07:02 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	step_math(t_data *data)
{
	if(data->ray.ray_dirx < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pos_x - data->ray.map_x) \
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pos_x) \
			* data->ray.delta_dist_x;
	}
	if(data->ray.ray_diry < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y) \
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pos_y) \
			* data->ray.delta_dist_y;
	}
}

void	calcs(t_data *data, int x)
{
	data->ray.camera_x = 2 * x / data->win.x - 1;
	data->ray.ray_dirx = data->ray.dir_x + data->ray.plane_x \
		* data->ray.camera_x;
	data->ray.ray_diry = data->ray.dir_y + data->ray.plane_y \
		* data->ray.camera_x;
	data->ray.delta_dist_x = fabs(1 / data->ray.ray_dirx);
	data->ray.delta_dist_y = fabs(1 / data->ray.ray_diry);
	data->ray.map_x = (int) data->ray.pos_x;
	data->ray.map_y = (int) data->ray.pos_y;
	data->ray.hit = 0;
	data->ray.side = 0;
}

void	dda_calcs(t_data *data)
{
	while (data->ray.hit == 0)
	{
			if (data->ray.side_dist_x < data->ray.side_dist_y)
			{
				data->ray.side_dist_x += data->ray.delta_dist_x;
				data->ray.map_x += data->ray.step_x;
				data->ray.side = 0;
			}
			else
			{
				data->ray.side_dist_y += data->ray.delta_dist_y;
				data->ray.map_y += data->ray.step_y;
				data->ray.side = 1;
			}
			if (data->map->map_array[data->ray.map_y][data->ray.map_x] != '0')
				data->ray.hit = 1;
	}
}

int	ray(t_data *data)
{
	int	x;

	x = 0;
	while (x++ < data->win.x)
	{
		calcs(data, x);
		step_math(data);
		dda_calcs(data);
	}
	return (0);
}