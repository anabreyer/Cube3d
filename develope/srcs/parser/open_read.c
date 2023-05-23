/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:11:44 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 19:21:23 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_parser(t_cub *cub, char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("cannot open file", cub, NULL);
	init_map(&cub->map, cub);
	cub->player.status = 0;
	file_parser_util(line, fd, cub);
	dup_map(cub, filename);
	close(fd);
	return (0);
}

void	file_parser_util(char*line, int fd, t_cub *cub)
{
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = replace_char(line);
		cub->map.mcount++;
		if (file_check(&cub->map, &cub->player, line, cub))
		{
			free(line);
			print_error("missing or wrong data in map file", cub, NULL);
		}
		free(line);
		line = NULL;
	}
}
