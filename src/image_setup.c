#include "../cub3d.h"

void	init_image(t_data *data, t_img *image)
{
	image->mlx_img = mlx_new_image(data->mlx_ptr, data->win.x, \
		data->win.y);
	image->addr = mlx_get_data_addr(image->mlx_img, \
		&image->bits_per_pixel, &image->line_length, \
			&image->endian);
	draw_floor(data);
	draw_ceiling(data);
}

void	pix(t_img *img, int x, int y, int color)
{
	char		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	draw_vert_line(t_img *img, t_point draw_start, t_point draw_end, \
			int color)
{
	while (draw_start.x >= 0 && draw_start.y >= 0 && draw_start.y <= draw_end.y)
	{
		pix(img, draw_start.x, draw_start.y, color);
		draw_start.y++;
	}
}

void	draw_ceiling(t_data *data)
{
	int	x;
	int	red;
	int	green;
	int	blue;

	red = data->map->ceiling_color[0];
	green = data->map->ceiling_color[1];
	blue = data->map->ceiling_color[2];
	x = 0;
	data->ray.color = encode_rgb(red, green, blue);
	while (x <= data->win.x)
	{
		draw_vert_line(data->img, (t_point){x, 0}, \
		(t_point){x, data->win.y / 2}, data->ray.color);
		x++;
	}
}

void	draw_floor(t_data *data)
{
	int	x;
	int	red;
	int	green;
	int	blue;

	red = data->map->floor_color[0];
	green = data->map->floor_color[1];
	blue = data->map->floor_color[2];
	x = 0;
	data->ray.color = encode_rgb(red, green, blue);
	while (x <= data->win.x)
	{
		draw_vert_line(data->img, (t_point){x, data->win.y / 2}, \
		(t_point){x, data->win.y}, data->ray.color);
		x++;
	}
}