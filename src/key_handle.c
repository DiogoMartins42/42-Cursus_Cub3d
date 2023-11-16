/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:13:07 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/16 12:13:10 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_release(int key, t_data *data)
{
	if(key == XK_w)
		data->moves.w = false;
	if(key == XK_s)
		data->moves.s = false;
	if(key == XK_a)
		data->moves.a = false;
	if(key == XK_d)
		data->moves.d = false;
	if(key == XK_Left)
		data->moves.rotate_l = false;
	if(key == XK_Right)
		data->moves.rotate_r = false;
	return (0);
}

int	handle_press(int key, t_data *data)
{
	if(key == XK_w)
		data->moves.w = true;
	if(key == XK_s)
		data->moves.s = true;
	if(key == XK_a)
		data->moves.a = true;
	if(key == XK_d)
		data->moves.d = true;
	if(key == XK_Left)
		data->moves.rotate_l = true;
	if(key == XK_Right)
		data->moves.rotate_r = true;
	if(key == XK_Escape)
		exit_game(data);
	return (0);
}
