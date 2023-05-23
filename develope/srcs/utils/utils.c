/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:27 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 14:50:28 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg, t_cub *cub)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Error\n", 2);
	freeandexit(cub);
}

int	skip_spacei(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
