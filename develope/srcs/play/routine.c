/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:49:29 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 14:49:31 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_game(t_cub *cub)
{
	paint_floor_ceiling(cub);
	raycasting(cub);
	draw_image(cub);
	key_act_hooking(cub);
}

int	routine(t_cub *cub)
{
	create_window(cub);
	init_image(&cub->img, cub);
	create_image(cub);
	init_player(&cub->player);
	init_key(&cub->key);
}
