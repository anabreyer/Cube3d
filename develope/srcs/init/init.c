/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:22 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 14:40:26 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_key(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->turn_l = 0;
	key->turn_r = 0;
}

void	init_sidedist(t_raycasting *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	init_ray(t_cub *cub, int x)
{
	double	camera;

	camera = 2 * x / (double)WWIDTH - 1;
	if (x == (WWIDTH - 1))
		camera = 1.0;
	cub->ray.raydir_x = cub->player.dir_x + cub->player.plane_x * camera;
	cub->ray.raydir_y = cub->player.dir_y + cub->player.plane_y * camera;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	cub->ray.deltadist_x = fabs(1 / cub->ray.raydir_x);
	cub->ray.deltadist_y = fabs(1 / cub->ray.raydir_y);
	init_sidedist(&cub->ray, &cub->player);
}

void	init_player_2(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

void	init_player(t_player *player)
{
	init_player_2(player);
	if (player->status == NO)
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	else if (player->status == SO)
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
	else if (player->status == WE)
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
	else if (player->status == EA)
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	player->speed_move = 0.06;
	player->speed_rotate = 0.05;
}
