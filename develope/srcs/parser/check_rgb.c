/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:59 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 16:26:02 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_range(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{	
		while (line[i] && (ft_isspace(line[i]) || line[i] == ','))
			i++;
		if (ft_isdigit(line[i]))
		{
			if (!(ft_atoi(line + i) >= 0 && ft_atoi(line + i) <= 255))
				return (1);
			while (ft_isdigit(line[i]))
				i++;
		}
	}
	return (0);
}

int	check_syntax_rgb(char *line, t_cub *cub)
{
	int	i;
	int	comma;
	int	count;

	i = 0;
	comma = 0;
	count = 0;
	while (line && line[i])
	{
		if (line[i] == ',')
			comma++;
		if (!ft_isspace(line[i]) && !ft_isdigit(line[i]) && line[i] != ',')
			print_error("found non-numeric for rgb", cub);
		if (!ft_isdigit(line[i]) && ft_isdigit(line[i + 1]))
			count++;
		i++;
	}
	if (comma != 2 || count > 3)
	{
		return (print_error("rgb syntax error", cub), -1);
	}
	return (check_range(line));
}

void	rgb_split(char *line, int rgb[3], char sep)
{
	int	i;

	i = 0;
	while (line && *line && i < 3)
	{
		while (*line && (ft_isspace(*line) || *line == ','))
			line++;
		rgb[i] = ft_atoi(line);
		i++;
		while (*line && ft_isdigit(*line))
			line++;
	}
}

int	check_color(char *line, char key, t_cub *cub)
{
	int	i;

	line += 2;
	while (ft_isspace(*line))
		line++;
	if (check_syntax_rgb(line, cub))
	{
		print_error("rgb range error: (0-255)", cub);
	}
	i = 0;
	if (key == 'C')
	{
		rgb_split(line, cub->map.rgb_c, ',');
		cub->map.ceiling = (cub->map.rgb_c[0] << 16 | \
			cub->map.rgb_c[1] << 8 | cub->map.rgb_c[2]);
	}
	else if (key == 'F')
	{
		rgb_split(line, cub->map.rgb_f, ',');
		cub->map.floor = (cub->map.rgb_f[0] << 16 | \
			cub->map.rgb_f[1] << 8 | cub->map.rgb_f[2]);
	}
	return (0);
}
