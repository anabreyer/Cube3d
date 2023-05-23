/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:42 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 14:44:20 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path(char *line, t_cub *cub)
{
	int		fd;
	char	*p;

	p = line;
	p += 2;
	while (ft_isspace(*p))
		p++;
	fd = open(p, O_RDONLY);
	if (fd < 0)
		print_error("cannot open texture image file", cub);
	close(fd);
	return (p);
}

int	check_path(char *line, t_cub *cub)
{
	char	*path;

	path = get_path(line, cub);
	if (!path)
		return (1);
	if (line[0] == 'N' && cub->map.img_path[0] == NULL)
	{	
		cub->map.img_path[0] = ft_strdup(path);
	}
	else if (line[0] == 'S' && cub->map.img_path[1] == NULL)
	{
		cub->map.img_path[1] = ft_strdup(path);
	}
	else if (line[0] == 'W' && cub->map.img_path[2] == NULL)
	{
		cub->map.img_path[2] = ft_strdup(path);
	}
	else if (line[0] == 'E' && cub->map.img_path[3] == NULL)
	{
		cub->map.img_path[3] = ft_strdup(path);
	}
	else
		print_error("double keyword for the texture file", cub);
	return (0);
}

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
