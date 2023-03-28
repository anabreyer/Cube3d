/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:58:12 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:58:13 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_long	solong;

	initvar(&solong);
	if (argc == 1)
		showerror(&solong, "Missing map (./so_long maps/intra.ber)");
	if (argc > 2)
		showerror(&solong, "Too many arguments");
	parsing(&solong, argv[1]);
	display(&solong);
	return (0);
}
