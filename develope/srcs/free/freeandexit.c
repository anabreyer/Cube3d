/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:25:50 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/24 16:35:21 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	freeandexit(t_cub *cub, char *line)
{
	if (line)
		free(line);
	if (cub->mlx)
	{
		mlx_destroy_image(cub->mlx, cub->img.img);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	freemap(cub);
	free_img_arr(cub);
	exit(0);
}

int	freemap(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map.map && cub->map.map[i])
	{
		free(cub->map.map[i]);
		i++;
	}
	if (cub->map.map)
		free(cub->map.map);
	i = 0;
	while (i < 4)
	{
		if (cub->map.img_path[i] != NULL)
			free(cub->map.img_path[i]);
		i++;
	}
	return (0);
}

int	free_img_arr(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->img.img_arr)
	{
		while (i < 4)
		{
			if (cub->img.img_arr[i])
				free(cub->img.img_arr[i]);
			i++;
		}
		free(cub->img.img_arr);
	}
	return (0);
}
