/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:59:11 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/24 19:16:48 by dreis-ma         ###   ########.fr       */
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

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_player
{
	t_point	init_pos;
	char	init_dir;
}	t_player;

typedef struct s_movement
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	rotate_r;
	bool	rotate_l;
}	t_movement;

typedef struct s_ray
{
	double		pos_x;
	double 		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dirx;
	double		ray_diry;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wdist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			color;

}	t_ray;

typedef struct s_map
{
	char		*map_file;
	bool		duplicated_elements;
	int			width;
	int			height;
	int 		map_start;
	char		**map_array;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int 		*floor_color;
	int 		*ceiling_color;
	int 		p_init_x;
	int 		p_init_y;
	char		p_init_dir;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			id;
	int			diff_x;
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
	t_movement	moves;
	//t_img		*mini;
	//t_img		*prev_mini;
	t_map		*map;

}	t_data;

// Validate file & map:
bool	validate_file(char *map_file, t_map *map);
int		check_file_type(char *map_file);
int		check_open_file(char *map_file);
bool	validate_map(int fd, t_map *map);
int		*save_rgb(char *str);
bool	check_invalid_line(char *line);
bool	read_map(int fd, t_map *map, char *line);
bool	check_all_elements(t_map *map);
bool	validate_walls(t_map *map);
char	*fill_line(char *line, int width);

int		check_width(char *line);

void			cleanup_map(t_map *map);
void			cleanup_map_array_2(char **map_array, int j);
void			init_game(t_data *data);

int				ray(t_data *data);

void			color_select(t_data *data);
int				rgb_converter(int red, int green, int blue);
unsigned int	gix(t_img *img, int x, int y);
void			pix(t_img *img, int x, int y, int color);
void			texturing(t_data *data, int x, int id);

int				exit_game(t_data *data);

int				handle_press(int key, t_data *data);
int				handle_release(int key, t_data *data);
void			movement_a_press(t_data *data, double move_spd);
void			movement_d_press(t_data *data, double move_spd);
void			movement_s_press(t_data *data, double move_spd);
void			movement_w_press(t_data *data, double move_spd);
int				movement_press(t_data *data);
void			rotate_left(t_data *data, double move_spd);
void			rotate_rigth(t_data *data, double move_spd);

void	init_image(t_data *data, t_img *image);

#endif
