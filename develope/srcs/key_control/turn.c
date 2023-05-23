/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:36:50 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 14:38:37 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_l(t_player *player, t_map *map)
{
	double	old_dir;
	double	old_plane;

	old_dir = player->dir_y;
	old_plane = player->plane_y;
	player->dir_y = player->dir_x * sin(-(player->speed_rotate)) \
		+ player->dir_y * cos(-(player->speed_rotate));
	player->dir_x = player->dir_x * cos(-(player->speed_rotate)) \
		- old_dir * sin(-(player->speed_rotate));
	player->plane_y = player->plane_x * sin(-(player->speed_rotate)) \
		+ player->plane_y * cos(-(player->speed_rotate));
	player->plane_x = player->plane_x * cos(-(player->speed_rotate)) \
		- old_plane * sin(-(player->speed_rotate));
}

void	turn_r(t_player *player, t_map *map)
{
	double	old_dir;
	double	old_plane;

	old_dir = player->dir_y;
	old_plane = player->plane_y;
	player->dir_y = player->dir_x * sin(player->speed_rotate) \
		+ player->dir_y * cos(player->speed_rotate);
	player->dir_x = player->dir_x * cos(player->speed_rotate) \
		- old_dir * sin(player->speed_rotate);
	player->plane_y = player->plane_x * sin(player->speed_rotate) \
		+ player->plane_y * cos(player->speed_rotate);
	player->plane_x = player->plane_x * cos(player->speed_rotate) \
		- old_plane * sin(player->speed_rotate);
}
