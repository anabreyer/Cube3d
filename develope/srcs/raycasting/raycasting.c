/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:44:38 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/24 16:33:56 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_dda(t_raycasting *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
}

/*
(mapX - posX + (1 - stepX) / 2) / rayDirX = sideDistX - deltaDistX
therefore,
	perWallDist = sideDistZ - deltaDistX
*/

/*
delta = 1/ray

step = 1
side = (map + 1 - pos) * delta

(map - pos + (1 - 1) / 2) / rayDirX = side - delta
map - pos = (side - delta) * ray
map - pos = ((map + 1 - pos) * 1 / ray * ray) - (1 / ray * ray)
map - pos = map - pos + 1 - 1
map - pos = map - pos

step = -1
side = (pos - map) * delta
(map - pos + (1 - (-1) / 2) / rayDir = side - delta
map - pos + 1 = (side - delta) *ray
map - pos + 1 = ((pos - map) * delta - delta) * ray

if (step = -1)
	ray < 0
map - pos + 1 = ((pos - map) * 1 / ray * ray) - (1 / ray * ray)
map - pos + 1 = -pos + map + 1
*/

void	pre_buffer(t_raycasting *ray, t_player *player)
{
	double	wall;

	if (ray->side == 0)
		wall = player->pos_y + (ray->perpwalldist * ray->raydir_y);
	else
		wall = player->pos_x + (ray->perpwalldist * ray->raydir_x);
	wall = wall - floor(wall);
	ray->tex_x = (int)(wall * (double)64);
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	ray->line_height = (int)(WHEIGHT / ray->perpwalldist);
	ray->startpoint = WHEIGHT / 2 - ray->line_height / 2;
	ray->endpoint = WHEIGHT / 2 + ray->line_height / 2;
	if (ray->startpoint < 0)
		ray->startpoint = 0;
	if (ray->endpoint >= WHEIGHT)
		ray->endpoint = WHEIGHT;
	ray->ratio = 1.0 * 64 / ray->line_height;
	ray->t_pos = (ray->startpoint - WHEIGHT / 2 + ray->line_height / 2) \
		* ray->ratio;
}

void	set_buffer(t_raycasting *ray, t_image *img, int x)
{
	int	y;
	int	color;

	y = ray->startpoint;
	while (y < ray->endpoint)
	{
		ray->tex_y = (int)ray->t_pos & (64 - 1);
		if (ray->side == 0)
		{
			if (ray->raydir_x >= 0)
				color = img->img_arr[EA - 1][64 * ray->tex_y + ray->tex_x];
			else
				color = img->img_arr[WE - 1][64 * ray->tex_y + ray->tex_x];
		}
		else if (ray->side == 1)
		{
			if (ray->raydir_y >= 0)
				color = img->img_arr[SO - 1][64 * ray->tex_y + ray->tex_x];
			else
				color = img->img_arr[NO - 1][64 * ray->tex_y + ray->tex_x];
		}
		img->buffer[y][x] = color;
		ray->t_pos += ray->ratio;
		y++;
	}
}

void	raycasting(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WWIDTH)
	{
		init_ray(cub, x);
		calculate_dda(&cub->ray, &cub->map);
		pre_buffer(&cub->ray, &cub->player);
		set_buffer(&cub->ray, &cub->img, x);
		x++;
	}
}

// void	verLine(t_cub *cub, int x, int y1, int y2, int color)
// {
// 	int tmp;

// 	tmp = y1;
// 	while (tmp <= y2)
// 	{
// 		mlx_pixel_put(cub->mlx, cub->win, x, tmp, color);
// 		tmp++;
// 	}
// }

// void	paint_untextured_wall(t_raycasting *ray, t_cub *cub, int x)
// {
// 	int color;

// 	ray->line_height = (int)WHEIGHT / ray->perpwalldist;

// 	ray->startpoint = WHEIGHT / 2 - ray->line_height / 2;
// 	ray->endpoint = WHEIGHT / 2 + ray->line_height / 2;
// 	if (ray->startpoint < 0)
// 		ray->startpoint = 0;
// 	if (ray->endpoint >= WHEIGHT)
// 		ray->endpoint = WHEIGHT - 1;

// 	if (cub->map.map[ray->map_y][ray->map_x] == '1')
// 		color = 0x894a87;
// 	if (ray->side == 1)
// 		color = color / 2;

// 	verLine(cub, x, ray->startpoint, ray->endpoint, color);
// }
