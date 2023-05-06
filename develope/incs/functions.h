
# ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "cub3d.h"

/* UTILS */
int     ft_isspace(char c);
int     skip_spacei(char *str);
void    print_error(char *msg, t_cub *cub);

/* PARSER */
int     check_extension(char *filename);
int     check_path(char *line, t_cub *cub);
int     file_parser(t_cub *cub, char *filename);
int     check_color(char *line, char key, t_cub *cub);
void    dup_map(t_cub *cub, char *filename);

/* INIT */
void    init_player(t_player *player);
void    init_map(t_map *map, t_cub *cub);
int     init_cub(t_cub *cub, char *str);
void    init_image(t_image *img, t_cub *cub);

/* PLAY */
int     routine(t_cub *cub);
int     create_window(t_cub *cub);
void    create_image(t_cub *cub);
int     go_hooking(t_cub *cub);

/* FREE */
int     closebutton(t_cub *cub);
int     freeandexit(t_cub *cub);
int     freemap(t_cub *cub);
int     free_img_arr(t_cub *cub);

/* MAIN */
int     main(int argc, char *argv[]);

#endif