/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:55 by dmanuel-          #+#    #+#             */
/*   Updated: 2024/01/30 11:43:00 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texturing2( t_data *data, int x, int id, t_point *texture)
{
	double	texture_pos;
	double	step;
	int		y;

	step = 1.0 * 64 / data->ray.line_h;
	texture_pos = (data->ray.draw_start - (data->win.y / 2) + \
		data->ray.line_h / 2) * step;
	y = data->ray.draw_start;
	while (y < data->ray.draw_end && y < data->win.y)
	{
		texture->y = ((int) texture_pos & (64 - 1));
		texture_pos += step;
		if (x >= 0 && y >= 0 && texture->x >= 0 && texture->y >= 0)
		{
			data->ray.color = gix(data->tex_img[id], texture->x, texture->y);
			pix(data->img, x, y, data->ray.color);
		}
		y++;
	}
}

void	texturing(t_data *data, int x, int id)
{
	double	wall_x;
	t_point	texture;

	if (data->ray.side == 0)
	{
		wall_x = data->ray.pos_y + data->ray.perp_wdist * \
			data->ray.ray_diry;
		wall_x -= data->ray.map_y;
	}
	else
	{
		wall_x = data->ray.pos_x + data->ray.perp_wdist * \
			data->ray.ray_dirx;
		wall_x -= data->ray.map_x;
	}
	texture.x = (int)(wall_x * (double)64);
	texture.x = 64 - texture.x - 1;
	texturing2(data, x, id, &texture);
}

unsigned int	gix(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_length) + \
	x * (img->bits_per_pixel / 8))));
}

int	rgb_converter(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}
