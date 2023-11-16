/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:42 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/16 13:55:57 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data, double move_spd)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(move_spd) - \
		data->ray.dir_x * sin(move_spd);
	data->ray.dir_y = old_dir_x * sin(move_spd) + \
		data->ray.dir_y * cos(move_spd);
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(move_spd) - \
		data->ray.plane_y * sin(move_spd);
	data->ray.plane_y = old_plane_x * sin(move_spd) + \
		data->ray.plane_y * cos(move_spd);
}

void	rotate_rigth(t_data *data, double move_spd)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(-move_spd) - \
		data->ray.dir_x * sin(-move_spd);
	data->ray.dir_y = old_dir_x * sin(-move_spd) + \
		data->ray.dir_y * cos(-move_spd);
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(-move_spd) - \
		data->ray.plane_y * sin(-move_spd);
	data->ray.plane_y = old_plane_x * sin(-move_spd) + \
		data->ray.plane_y * cos(-move_spd);
}
