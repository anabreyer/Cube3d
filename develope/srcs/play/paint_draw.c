/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:50 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 14:48:52 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_floor_ceiling(t_cub *cub)
{
	int	y;
	int	x;
	int	floor;
	int	ceiling;

	y = 0;
	floor = cub->map.floor;
	ceiling = cub->map.ceiling;
	while (y < WHEIGHT / 2)
	{
		x = 0;
		while (x < WWIDTH)
		{
			cub->img.buffer[y][x] = ceiling;
			cub->img.buffer[WHEIGHT - y - 1][x] = floor;
			x++;
		}
		y++;
	}
}

void	draw_image(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < WHEIGHT)
	{
		x = 0;
		while (x < WWIDTH)
		{
			cub->img.data[y * WWIDTH + x] = cub->img.buffer[y][x];
			x++;
		}
		y++;
	}
	init_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}
