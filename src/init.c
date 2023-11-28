/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:01 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/24 19:49:39 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_dirns(t_data *data)
{
	if ('N' == data->player.init_dir)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
		data->ray.plane_x = 1;
		data->ray.plane_y = 0;
	}
	else if ('S' == data->player.init_dir)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
		data->ray.plane_x = -1;
		data->ray.plane_y = 0;
	}
}

void	set_dirwe(t_data *data)
{
	if ('E' == data->player.init_dir)
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = 1;
	}
	else if ('W' == data->player.init_dir)
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = -1;
	}
}

void	direction(t_data *data)
{
	if ('N' == data->player.init_dir)
		set_dirns(data);
	if ('S' == data->player.init_dir)
		set_dirns(data);
	if ('E' == data->player.init_dir)
		set_dirwe(data);
	if ('W' == data->player.init_dir)
		set_dirwe(data);
}

int	movement_press(t_data *data)
{
	double	move_spd;

	move_spd = 0.1;
	if (data->moves.w == true)
		movement_w_press(data, move_spd);
	if (data->moves.s == true)
		movement_s_press(data, move_spd);
	if (data->moves.a == true)
		movement_a_press(data, move_spd);
	if (data->moves.d == true)
		movement_d_press(data, move_spd);
	if (data->moves.rotate_l == true)
		rotate_left(data, move_spd);
	if (data->moves.rotate_r == true)
		rotate_rigth(data, move_spd);
	return (0);
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.x,
			data->win.y, "Cub3D");
	data->ray.pos_x = data->player.init_pos.x + 0.5;
	data->ray.pos_y = data->player.init_pos.y + 0.5;
	direction(data);
	image_load(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_press, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyPressMask, &handle_release, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_loop_hook(data->mlx_ptr, &ray, data);
	mlx_loop(data->mlx_ptr);
}
