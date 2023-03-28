/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:50 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:48:16 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_keyboard(int keycode, t_long *sl)
{
	char	*num;

	num = ft_itoa(sl->move);
	sl->line = ft_strjoin("Move: ", num);
	free(num);
	if (keycode == W || keycode == UP)
		moveplayer(1, sl);
	if (keycode == S || keycode == DOWN)
		moveplayer(-1, sl);
	if (keycode == LEFT || keycode == A)
		moveplayer(2, sl);
	if (keycode == RIGHT || keycode == D)
		moveplayer(3, sl);
	if (keycode == ESC)
		freeandexit(sl);
	pos_player(sl);
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	mlx_string_put(sl->mlx_ptr, sl->mlx_win, 10, 20, 0xffffff, sl->line);
	free(sl->line);
	return (0);
}

int	closebyredbutton(t_long *sl)
{
	mlx_destroy_image(sl->mlx_ptr, sl->img);
	exit (0);
	return (0);
}
