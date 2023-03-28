/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:46:02 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:47:04 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	display(t_long *sl)
{
	createwindow(sl);
	loadtexture(sl);
	render(sl);
	write(1, "MOVE : ", 8);
	ft_putnbr(sl->move);
	pos_player(sl);
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	go_hooking(sl);
	return (0);
}

int	go_hooking(t_long *sl)
{
	mlx_hook(sl->mlx_win, 2, 1L, ft_keyboard, sl);
	mlx_hook(sl->mlx_win, 33, 1L << 17, closebyredbutton, sl);
	mlx_loop(sl->mlx_ptr);
	return (0);
}

int	render(t_long *sl)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < sl->y)
	{
		while (x < sl->x)
		{
			sl->casein++;
			gettextnum(x, y, sl);
			printtexture(sl, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	createwindow(t_long *sl)
{
	sl->mlx_ptr = mlx_init();
	sl->img = mlx_new_image(sl->mlx_ptr, sl->xscreen, sl->yscreen);
	sl->pxl = mlx_get_data_addr(sl->img,
			&(sl->bpp), &(sl->s_line),
			&(sl->ed));
	sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->xscreen,
			sl->yscreen, "42 so_long aaduan-b");
	return (0);
}
