/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:59:11 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/02 17:24:46 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//# include "minilibx-linux/mlx.h"
# include "libft/include/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	win;
}	t_data;

typedef struct s_map
{
	int			starting_pos;
	char 		c_starting_pos;
	char		**map_array;
	char		**map_array_val;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
}				t_map;

bool	validate_map(char *file);

#endif