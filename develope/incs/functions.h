/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:32:09 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/05/23 16:31:37 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

/* UTILS */
int		ft_isspace(char c);
int		skip_spacei(char *str);
void	print_error(char *msg, t_cub *cub);

/* PARSER */
int		check_extension(char *filename);
int		check_path(char *line, t_cub *cub);
int		file_parser(t_cub *cub, char *filename);
int		file_check(t_map *map, t_player *player, char *line, t_cub *cub);
int		check_color(char *line, char key, t_cub *cub);
void	dup_map(t_cub *cub, char *filename);
void	file_parser_util(char*line, int fd, int i, t_cub *cub);

/* INIT */
void	init_key(t_key *key);
void	init_ray(t_cub *cub, int x);
void	init_player(t_player *player);
void	init_player_2(t_player *player);
void	init_map(t_map *map, t_cub *cub);
void	init_cub(t_cub *cub);
void	init_image(t_image *img, t_cub *cub);

/* MOVE */
void	move_w(t_player *player, t_map *map);
void	move_s(t_player *player, t_map *map);
void	move_a(t_player *player, t_map *map);
void	move_d(t_player *player, t_map *map);
void	turn_l(t_player *player, t_map *map);
void	turn_r(t_player *player, t_map *map);

/* KEY CONTROL */
int		key_press(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
int		key_act_hooking(t_cub *cub);

/* PLAY */
int		loop_game(t_cub *cub);
void	draw_image(t_cub *cub);
void	paint_floor_ceiling(t_cub *cub);
void	raycasting(t_cub *cub);
int		routine(t_cub *cub);
int		create_window(t_cub *cub);
void	create_image(t_cub *cub);
int		go_hooking(t_cub *cub);
int		keyboard(int keycode, t_cub *cub);
void	init_minimap(t_cub *cub);

/* FREE */
int		closebutton(t_cub *cub);
int		freeandexit(t_cub *cub);
int		freemap(t_cub *cub);
int		free_img_arr(t_cub *cub);

/* MAIN */
int		main(int argc, char *argv[]);

#endif
