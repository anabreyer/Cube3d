
# ifndef STRUCTURES_H
#define STRUCTURES_H

#include "cub3d.h"

# define WWIDTH 1280
# define WHEIGHT 960

// mlx_new_window
// mlx_clear_window
// mlx_destroy_window

// mlx_new_image :*****
        // mlx_pixel_put is too slow, so we need to buffering every pixels to imaghe

// mlx_put_image_to_window
// mlx_get_data_addr :******
    // char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,int *size_line,int *endian)
//
// mlx_destroy_image
// mlx_get_color_value
// mlx_xpm_to_image
// mlx_xpm_file_to_image
    // void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height)
// xml_png_file_to_image

// mlx_pixel_put
// mlx_string_put

// mlx_loop
// mlx_key_hook
// mlx_mouse_hook
// mlx_expose_hook

typedef struct s_player
{
    int         status;
    double      pos_x;
    double      pos_y;
    double      dir_x;
    double      dir_y;
    double      plane_x;
    double      plane_y;
}               t_player;

typedef struct s_image
{
    // mlx_get_data_addr
    // mlx_new_image
    void        *img;
	int		    *addr;
    int         **img_arr;
    int         buffer[WHEIGHT][WWIDTH];
    int         bpp;
    int         endian; //(0-1) value to choose color in pixel
    int         size_line;  //bite to save a line for image in memory
    int         width;
    int         height;
}               t_image;

// typedef struct s_texture
// {
//     char        *img_path[4];
//     int         floor;
//     int         ceiling;
//     int         rgb_f[3];
//     int         rgb_c[3];
// }				t_texture;

typedef struct s_map
{
    int         width;
    int         height;
    int         start;
    int         mcount;
    char        **map;
    char        *img_path[4];
    int         floor;
    int         ceiling;
    int         rgb_f[3];
    int         rgb_c[3];
}               t_map;

typedef struct s_cub
{
    void        *mlx;
    void        *win;
    t_map       map;
    t_image     img;
    t_player    player;
}               t_cub;

#endif