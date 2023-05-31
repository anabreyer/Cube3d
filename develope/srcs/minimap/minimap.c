/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:23:02 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/24 16:36:48 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_put_pixel(t_image *img, unsigned int colour, int x, int y)
{
	y += 15;
	x += 70;
	if (y >= WHEIGHT || x >= WWIDTH || x < 0 \
		|| y < 0 || ((y * WWIDTH + x) >= (WWIDTH * WHEIGHT - 1)))
		return (1);
	img->data[y * WWIDTH + x] = colour;
	return (0);
}

void	draw_square(t_cub *cub, int x, int y, int colour)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = x;
	j = y;
	height = MINIMAP_SIZE;
	width = height;
	while (i < width + x)
	{
		j = y;
		while (j < height + y)
		{
			ft_put_pixel(&cub->img, colour, j, i);
			j++;
		}
		i++;
	}
}

int	get_colour_minimap(t_map *map, int i, int j, t_player *player)
{
	int	colour;

	if (map->map[i][j] == '1')
		colour = COLOUR_MAP_WALL;
	if (ft_strchr("NSEW0", map->map[i][j]))
		colour = COLOUR_MAP_FLOOR;
	if ((i == (int)player->pos_y && j == (int)player->pos_x))
	{
		colour = 0xff0000;
	}
	return (colour);
}

void	init_minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	colour;
	int	offset_x;

	if (!cub->map.minimap)
		return ;
	offset_x = cub->map.width / 2 - \
		(ft_strlen(cub->map.map[0]) * MINIMAP_SIZE) / 2;
	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			colour = get_colour_minimap(&cub->map, i, j, &cub->player);
			draw_square(cub, i * MINIMAP_SIZE, \
				offset_x + j * MINIMAP_SIZE, colour);
			j++;
		}
		i++;
	}
}
