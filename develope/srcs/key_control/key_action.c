/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:34:18 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 14:34:19 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_act_hooking(t_cub *cub)
{
	if (cub->key.w && !cub->key.s)
		move_w(&cub->player, &cub->map);
	if (cub->key.s && !cub->key.w)
		move_s(&cub->player, &cub->map);
	if (cub->key.a && !cub->key.d)
		move_a(&cub->player, &cub->map);
	if (cub->key.d && !cub->key.a)
		move_d(&cub->player, &cub->map);
	if (cub->key.turn_l && !cub->key.turn_r)
		turn_l(&cub->player, &cub->map);
	if (cub->key.turn_r && !cub->key.turn_l)
		turn_r(&cub->player, &cub->map);
	return (0);
}

int	closebutton(t_cub *cub)
{
	if (cub->img.img != NULL)
		mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	freeandexit (cub);
	return (0);
}

// 02:KeyPress
// 03:KeyRelease
// 04:ButtonPress
// 05:ButtonRelease
// 17:DestroyNotify
// 33:ClientMessage

int	key_press(int key, t_cub *cub)
{
	if (key == W)
		cub->key.w = 1;
	if (key == S)
		cub->key.s = 1;
	if (key == A)
		cub->key.a = 1;
	if (key == D)
		cub->key.d = 1;
	if (key == LEFT)
		cub->key.turn_l = 1;
	if (key == RIGHT)
		cub->key.turn_r = 1;
	if (key == ESC)
		freeandexit (cub);
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == W)
		cub->key.w = 0;
	if (key == S)
		cub->key.s = 0;
	if (key == A)
		cub->key.a = 0;
	if (key == D)
		cub->key.d = 0;
	if (key == LEFT)
		cub->key.turn_l = 0;
	if (key == RIGHT)
		cub->key.turn_r = 0;
	return (0);
}

int	go_hooking(t_cub *cub)
{
	mlx_hook(cub->win, 17, 1L << 17, closebutton, cub);
	mlx_hook(cub->win, 2, 0, &key_press, cub);
	mlx_hook(cub->win, 3, 0, &key_release, cub);
	mlx_loop_hook(cub->mlx, &loop_game, cub);
	mlx_loop(cub->mlx);
	return (0);
}
