/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:39:57 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 14:39:58 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map, t_cub *cub)
{
	int	i;

	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->mcount = 0;
	map->start = 0;
	i = 0;
	while (i < 4)
		map->img_path[i++] = NULL;
	i = 0;
	while (i < 3)
	{
		map->rgb_c[i] = -1;
		map->rgb_f[i] = -1;
		i++;
	}
	map->floor = 0;
	map->ceiling = 0;
	map->minimap = 1;
}

void	init_img_sub(t_image *img, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WHEIGHT)
	{
		j = 0;
		while (j < WWIDTH)
			img->buffer[i][j++] = 0;
		i++;
	}
	img->img_arr = (int **)malloc(4 * sizeof(int *));
	if (!img->img_arr)
		print_error("error: init_img_sub: img_arr malloc failed", cub);
	i = 0;
	while (i < 4)
	{
		img->img_arr[i] = (int *)malloc(sizeof(int) * 64 * 64);
		if (!img->img_arr[i])
			print_error("error: init_img_sub: img_arr malloc2 failed", cub);
		ft_memset(img->img_arr[i], 0, (sizeof(int) * 64 * 64));
		i++;
	}
}

void	init_image(t_image *img, t_cub *cub)
{
	img->img = NULL;
	img->data = NULL;
	img->img_arr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->size_line = 0;
	init_img_sub(img, cub);
}
