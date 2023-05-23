/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:59:15 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 16:50:16 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_status(char dir)
{
	if (dir == 'N')
		return (NO);
	else if (dir == 'S')
		return (SO);
	else if (dir == 'W')
		return (WE);
	else if (dir == 'E')
		return (EA);
}

void	check_mapsyntax(t_map *map, t_player *player, char *line, t_cub *cub)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c != 'N' && c != 'S' && c != 'E' && c != 'W' \
			&& c != '0' && c != '1' && c != ' ')
			print_error("wrong element on the map", cub);
		else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (player->status != 0)
				print_error("more than one players on the map", cub);
			player->status = set_status(c);
		}
		i++;
	}
	if (map->width < i)
		map->width = i;
	if (map->start == 0)
		map->start = map->mcount;
}

int	file_check(t_map *map, t_player *player, char *line, t_cub *cub)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) \
		|| !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		ret = check_path(line, cub);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
		ret = check_color(line, line[0], cub);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
	{
		if (!map->img_path[0] || !map->img_path[1] \
			|| !map->img_path[2] || !map->img_path[3] \
			|| map->rgb_c[0] == -1 || map->rgb_f[0] == -1)
			print_error("map error: something missing or the data " \
				"is in wrong order", cub);
		else
			check_mapsyntax(map, player, line, cub);
	}
	return (ret);
}

int	check_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i - 4] == '.' && filename[i - 3] == 'c'\
		&& filename[i - 2] == 'u' && filename[i - 1] == 'b')
		return (0);
	else
		print_error("wrong file extension .cub", NULL);
	return (1);
}
