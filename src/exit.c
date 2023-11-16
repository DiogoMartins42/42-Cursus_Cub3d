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

int	exit_game(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->img->mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	free(data);
	exit(0);
}
