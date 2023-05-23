/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:36:29 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 15:43:50 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

# define WWIDTH 1280
# define WHEIGHT 720

typedef struct s_player
{
	int		status;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	speed_move;
	double	speed_rotate;
}	t_player;

typedef struct s_image
{
	void	*img;
	int		*data;
	int		**img_arr;
	int		buffer[WHEIGHT][WWIDTH];
	int		bpp;
	int		endian;
	int		size_line;
	int		width;
	int		height;
}	t_image;

typedef struct s_raycasting
{
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	raydir_x;
	double	raydir_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		startpoint;
	int		endpoint;
	int		tex_x;
	int		tex_y;
	double	t_pos;
	double	ratio;
}	t_raycasting;

typedef struct s_map
{
	int		width;
	int		height;
	int		start;
	int		mcount;
	char	**map;
	char	*img_path[4];
	int		floor;
	int		ceiling;
	int		rgb_f[3];
	int		rgb_c[3];
	int		minimap;
}	t_map;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	turn_l;
	int	turn_r;
}	t_key;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_image			img;
	t_player		player;
	t_raycasting	ray;
	t_key			key;
}	t_cub;

#endif
