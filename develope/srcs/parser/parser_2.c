/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:11:44 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 15:12:13 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_parser(t_cub *cub, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("cannot open file", cub);
	init_map(&cub->map, cub);
	cub->player.status = 0;
	file_parser_util(line, fd, i, cub);
	dup_map(cub, filename);
	close(fd);
	return (0);
}

void	file_parser_util(char*line, int fd, int i, t_cub *cub)
{
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = -1;
		while (line && line[++i])
			if (line[i] == '\n')
				line[i] = '\0';
		cub->map.mcount++;
		if (file_check(&cub->map, &cub->player, line, cub))
			print_error("wrong data in map file", cub);
		free(line);
		line = NULL;
	}
	i = 0;
}
