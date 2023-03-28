/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:26 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:48:28 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	moveplayer(int nb, t_long *sl)
{
	if (nb == 1)
		if (sl->map[sl->player_y - 1][sl->player_x] != '1')
			displaymove(sl, nb);
	if (nb == -1)
		if (sl->map[sl->player_y + 1][sl->player_x] != '1')
			displaymove(sl, nb);
	if (nb == 2)
		if (sl->map[sl->player_y][sl->player_x - 1] != '1')
			displaymove(sl, nb);
	if (nb == 3)
		if (sl->map[sl->player_y][sl->player_x + 1] != '1')
			displaymove(sl, nb);
	return (0);
}

int	displaymove(t_long *sl, int nb)
{
	write(1, "\b\b\b\b\b\b\b\b\b\b\b", 12);
	if (nb == 1)
		sl->player_y--;
	if (nb == -1)
		sl->player_y++;
	if (nb == 2)
		sl->player_x--;
	if (nb == 3)
		sl->player_x++;
	sl->move++;
	write(1, "MOVE : ", 8);
	ft_putnbr(sl->move);
	checkaremove(sl);
	return (0);
}

int	checkaremove(t_long *sl)
{
	if (sl->map[sl->player_y][sl->player_x] == 'C')
	{
		sl->collectible++;
		sl->map[sl->player_y][sl->player_x] = '0';
	}
	if (sl->map[sl->player_y][sl->player_x] == 'E')
	{
		if (sl->collectible == sl->collectibletotal)
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 11);
			write(1, "Congratulation you finish with ", 31);
			ft_putnbr(sl->move);
			write(1, " moves. !!! :)\n", 15);
			freeandexit(sl);
		}
	}
	return (0);
}

int	pos_player(t_long *sl)
{
	if (sl->lastplayer_x != -1)
	{
		gettextnum(sl->lastplayer_x, sl->lastplayer_y, sl);
		printtexture(sl, sl->lastplayer_x, sl->lastplayer_y);
	}
	gettextnum(sl->player_x, sl->player_y, sl);
	printtexture(sl, sl->player_x, sl->player_y);
	sl->actualtext = 3;
	printtexture(sl, sl->player_x, sl->player_y);
	sl->lastplayer_x = sl->player_x;
	sl->lastplayer_y = sl->player_y;
	return (0);
}
