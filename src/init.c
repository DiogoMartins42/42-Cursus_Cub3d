/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:01 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/10/31 14:02:03 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_dirns(t_data *data)
{
	if('N'  == data->player.init_dir)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
		data->ray.plane_x = 1;
		data->ray.plane_y = 0;
	}
	else if('S'  == data->player.init_dir)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
		data->ray.plane_x = -1;
		data->ray.plane_y = 0;
	}
}

void	set_dirwe(t_data *data)
{
	if('E'  == data->player.init_dir)
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = 1;
	}
	else if('W'  == data->player.init_dir)
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = -1;
	}
}

void	direction(t_data *data)
{
	if('N'  == data->player.init_dir)
		set_dirns(data);
	if('S'  == data->player.init_dir)
		set_dirns(data);
	if('E'  == data->player.init_dir)
		set_dirwe(data);
	if('W'  == data->player.init_dir)
		set_dirwe(data);
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.x,
			data->win.y, "Cub3D");
	data->ray.pos_x = data->player.init_pos.x + 0.5;
	data->ray.pos_y = data->player.init_pos.y + 0.5;
	direction(data);
}
