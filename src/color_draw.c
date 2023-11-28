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

void	color_select(t_data *data)
{
	if (data->ray.ray_dirx < 0 && data->ray.side == 0)
	{
		data->id = 3;
		return;
	}
	else if (data->ray.side == 0)
	{
		data->id = 2;
		return;
	}
	if (data->ray.ray_diry < 0)
	{
		data->id  = 1;
		return;
	}
	else
	{
		data->id = 0;
		return;
	}
}

