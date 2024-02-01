/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:18:29 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/16 12:18:32 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_fail(t_data *data, t_map *map)
{
	free(data->img);
	free_text(data);
	cleanup_map(map);
	free(data);
}

void	free_text(t_data *data)
{
	int	i;

	i = 0;
	if (data->tex_img)
	{
		while (data->tex_img[i])
		{
			if (data->mlx_ptr)
				mlx_destroy_image(data->mlx_ptr, data->tex_img[i]->mlx_img);
			free(data->tex_img[i++]);
		}
	}
	free(data->tex_img);
}

int	exit_game(t_data *data)
{
	free_text(data);
	if (data->mlx_ptr)
	{
		if (data->img->mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	free(data->img);
	cleanup_map(data->map);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
