/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:54:08 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/24 16:31:09 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_map *map, char **m)
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
				else if (m[i - 1][j] == '\0' || m[i + 1][j] == '\0'\
					|| m[i][j - 1] == '\0' || m[i][j + 1] == '\0')
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
	char	*line;
	char	*str;

	i = 0;
	line = NULL;
	while (i < cub->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		line = replace_char(line);
		str = (char *)malloc(sizeof(char) * (cub->map.width + 1));
		if (!str)
		{
			free(tmp);
			print_error("malloc error: read_set_map", cub, line);
		}
		ft_memset(str, ' ', cub->map.width);
		str[cub->map.width] = '\0';
		tmp[i++] = ft_strcpy(str, line);
		free(line);
		line = NULL;
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
		if (!line)
			break;
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

	if (cub->map.start == 0)
		print_error("map not found", cub, NULL);
	if (cub->player.status == 0)
		print_error("player not found", cub, NULL);
	cub->map.height = cub->map.mcount - cub->map.start + 1;
	tmp = (char **)malloc(sizeof(char *) * (cub->map.height + 1));
	if (!tmp)
		print_error("map temp malloc error", cub, NULL);
	cub->fd[1] = open(filename, O_RDONLY);
	if (cub->fd[1] < 0)
		print_error("dup map file open error", cub, NULL);
	read_til_start(cub->fd[1], cub);
	read_set_map(cub->fd[1], cub, tmp);
	if (!tmp[cub->map.height - 1])
		print_error("map error", cub, NULL);
	tmp[cub->map.height] = 0;
	cub->map.map = tmp;
	if (check_wall(&cub->map, cub->map.map))
		print_error("map error: opened wall", cub, NULL);
	else
		printf("map is ready\n");
	set_player_pos(&cub->player, cub->map.map);
	close(cub->fd[1]);
	cub->fd[1] = 0;
}
