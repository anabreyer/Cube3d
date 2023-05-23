/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:53:54 by jischoi           #+#    #+#             */
/*   Updated: 2023/05/23 16:29:41 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;

	if (argc < 2)
		print_error("missing map file 🫥", NULL);
	else if (argc > 2)
		print_error("too many arguments 🫠", NULL);
	else if (argc == 2 && !check_extension(argv[1]))
	{
		init_cub(&cub);
		if (!file_parser(&cub, argv[1]))
		{
			routine(&cub);
			cub.img.img = mlx_new_image(cub.mlx, WWIDTH, WHEIGHT);
			cub.img.data = (int *)mlx_get_data_addr(cub.img.img, \
				&cub.img.bpp, &cub.img.size_line, &cub.img.endian);
			mlx_hook(cub.win, 17, 0, &closebutton, &cub);
			mlx_hook(cub.win, 2, 1L << 0, &key_press, &cub);
			mlx_hook(cub.win, 3, 1L << 1, &key_release, &cub);
			mlx_loop_hook(cub.mlx, &loop_game, &cub);
			mlx_loop(cub.mlx);
		}
		else
			freeandexit (&cub);
	}
	return (0);
}
