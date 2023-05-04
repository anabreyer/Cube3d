
# ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "cub3d.h"

/* UTILS */
int     ft_isspace(char c);
int     skip_spacei(char *str);
void    print_error(char *msg, t_cub *cub);

/* PARSER */
int     check_extension(char *filename);
int     check_path(t_map *map, char *line, t_cub *cub);
int     file_parser(t_cub *cub, char *filename);
int     check_color(t_map *map, char *line, char key, t_cub *cub);
void    dup_map(t_cub *cub, char *filename);

/* INIT */
void    init_map(t_map *map, t_cub *cub);
int     init_cub(t_cub *cub, char *str);
int     main(int argc, char *argv[]);

#endif