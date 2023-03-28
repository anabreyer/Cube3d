/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:14 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:47:15 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	put_pxl(t_long *sl, int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= sl->yscreen || x >= sl->xscreen || x < 0 \
	|| y < 0)
		return (0);
	dest = sl->pxl + sl->s_line * y + x * (sl->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}
