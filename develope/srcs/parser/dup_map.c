/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:54:08 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 14:58:38 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_map *map, char **m, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == '0' || m[i][j] == 'E' || m[i][j] == 'W' \
				|| m[i][j] == 'S' || m[i][j] == 'N')
			{
				if (i == 0 || j == 0 || i == map->height - 1 || !m[i][j + 1])
					return (1);
				else if (m[i - 1][j] == ' ' || m[i + 1][j] == ' '\
					|| m[i][j - 1] == ' ' || m[i][j + 1] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	read_set_map(int fd, t_cub *cub, char **tmp)
{
	int		i;
	int		j;
	char	*line;
	char	*str;

	i = 0;
	line = NULL;
	while (i < cub->map.height)
	{
		j = -1;
		line = get_next_line(fd);
		while (line && line[++j])
			if (line[j] == '\n')
				line[j] = '\0';
		str = (char *)malloc(sizeof(char) * (cub->map.width + 1));
		if (!str)
			print_error("malloc error: read_set_map", cub);
		ft_memset(str, ' ', cub->map.width);
		str[cub->map.width] = '\0';
		ft_strcpy(str, line);
		tmp[i] = str;
		free(line);
		line = NULL;
		i++;
	}
}

void	read_til_start(int fd, t_cub *cub)
{
	char	*line;
	int		i;

	i = 0;
	while (i < cub->map.start - 1)
	{
		line = get_next_line(fd);
		free(line);
		line = NULL;
		i++;
	}
}

void	set_player_pos(t_player *player, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'\
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				player->pos_y = y + 0.5;
				player->pos_x = x + 0.5;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	dup_map(t_cub *cub, char *filename)
{
	char	**tmp;
	int		fd;

	if (cub->map.start == 0)
		print_error("map not found", cub);
	if (cub->player.status == 0)
		print_error("player not found", cub);
	cub->map.height = cub->map.mcount - cub->map.start + 1;
	tmp = (char **)malloc(sizeof(char *) * (cub->map.height + 1));
	if (!tmp)
		print_error("map temp malloc error", cub);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("dup map file open error", cub);
	read_til_start(fd, cub);
	read_set_map(fd, cub, tmp);
	tmp[cub->map.height] = 0;
	cub->map.map = tmp;
	if (check_wall(&cub->map, cub->map.map, cub))
		print_error("map error: opened wall", cub);
	else
		printf("map is ready\n");
	set_player_pos(&cub->player, cub->map.map);
	close(fd);
}
