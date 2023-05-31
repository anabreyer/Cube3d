/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:33 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 19:17:55 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_img_arr(t_cub *cub, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->img.height)
	{
		x = 0;
		while (x < cub->img.width)
		{
			cub->img.img_arr[i][cub->img.width * y + x] = \
				cub->img.data[cub->img.height * y + x];
			x++;
		}
		y++;
	}
}

void	create_image(t_cub *cub)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 4)
	{
		path = cub->map.img_path[i];
		cub->img.img = mlx_xpm_file_to_image(cub->mlx, path, \
			&cub->img.width, &cub->img.height);
		if (!cub->img.img)
			print_error("error: mlx_xpm_file_to_image", cub, NULL);
		if (cub->img.width != 64 || cub->img.height != 64 || !cub->img.img)
			print_error("error: create_image: load xpm" \
				" file to image got an error", cub, NULL);
		cub->img.data = (int *)mlx_get_data_addr(cub->img.img, \
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
		set_img_arr(cub, i);
		mlx_destroy_image(cub->mlx, cub->img.img);
		i++;
	}
}

int	create_window(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		print_error("error: create_window: failed to init mlx", cub, NULL);
	cub->win = mlx_new_window(cub->mlx, WWIDTH, WHEIGHT, "Cub3D");
	if (!cub->win)
		print_error("error: create_window: failed to create window", cub, NULL);
	return (0);
}
