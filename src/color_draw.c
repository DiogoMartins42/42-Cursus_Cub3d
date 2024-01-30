/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:08:17 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/16 11:08:19 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_load2(t_data *data, int i)
{
	int	size;

	size = 64;
	data->tex_img[i]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->map->WE, &size, &size);
	data->tex_img[i]->addr = \
			mlx_get_data_addr(data->tex_img[i]->mlx_img, \
				&data->tex_img[i]->bits_per_pixel, \
					&data->tex_img[i]->line_length, \
						&data->tex_img[i]->endian);
	i++;
	data->tex_img[i]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->map->EA, &size, &size);
	data->tex_img[i]->addr = \
			mlx_get_data_addr(data->tex_img[i]->mlx_img, \
				&data->tex_img[i]->bits_per_pixel, \
					&data->tex_img[i]->line_length, \
						&data->tex_img[i]->endian);
}

void	image_load(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = 64;
	data->tex_img[i]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->map->NO, &size, &size);
	data->tex_img[i]->addr = \
			mlx_get_data_addr(data->tex_img[i]->mlx_img, \
				&data->tex_img[i]->bits_per_pixel, \
					&data->tex_img[i]->line_length, \
						&data->tex_img[i]->endian);
	i++;
	data->tex_img[i]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->map->SO, &size, &size);
	data->tex_img[i]->addr = \
			mlx_get_data_addr(data->tex_img[i]->mlx_img, \
				&data->tex_img[i]->bits_per_pixel, \
					&data->tex_img[i]->line_length, \
						&data->tex_img[i]->endian);
	i++;
	image_load2(data, i);
}

void	color_select(t_data *data)
{
	if (data->ray.ray_dirx < 0 && data->ray.side == 0)
	{
		data->id = 3;
		return ;
	}
	else if (data->ray.side == 0)
	{
		data->id = 2;
		return ;
	}
	if (data->ray.ray_diry < 0)
	{
		data->id = 1;
		return ;
	}
	else
	{
		data->id = 0;
		return ;
	}
}

