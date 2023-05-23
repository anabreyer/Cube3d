/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:27 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 19:16:56 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg, t_cub *cub, char *line)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\033[0;00m", 2);
	ft_putstr_fd("\n", 2);
	freeandexit(cub, line);
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

char	*replace_char(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str && str[i])
		{
			if (str[i] == '\n')
				str[i] = '\0';
			i++;
		}
	}
	return (str);
}
