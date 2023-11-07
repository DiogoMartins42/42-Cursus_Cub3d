/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:59:11 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/06 17:18:16 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
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

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_player
{
	t_point	init_pos;
	char		init_dir;
}	t_player;

typedef struct s_img
{
	void	*mlx_img;
}	t_img;

typedef struct s_ray
{
	double		pos_x;
	double 		pos_y;
}	t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			id;
	//double		mid_point;
	//double		max_fov;
	//double		min_fov;
	//t_point	fov_max;
	//t_point	fov_min;
	//t_point	mouse;
	//t_point	prev_mouse;
	t_vector	win;
	t_player	player;
	t_ray		ray;
	t_img		*img;
	t_img		**tex_img;
	//t_img		*mini;
	//t_img		*prev_mini;
}	t_data;

typedef struct s_map
{
	int			width;
	int			height;
	int			starting_pos;
	char 		c_starting_pos;
	char		**map_array;
	char		**map_array_val;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char 		*floor_color;
	char 		*ceiling_color;
}				t_map;

// Validate file & map:
bool	validate_file(char *map_file, t_map *map);
int		check_file_type(char *map_file);
int		check_open_file(char *map_file);
bool	validate_map(int fd, t_map *map, char *line, char *map_file);
void	setup_map(t_map *map);

void	cleanup_map(t_map *map);
void	init_game(t_data *data);

#endif
