
# ifndef STRUCTURES_H
#define STRUCTURES_H

#include "cub3d.h"


// mlx_new_window
// mlx_clear_window
// mlx_destroy_window

// mlx_new_image :*****
        // mlx_pixel_put is too slow, so we need to buffering every pixels to imaghe

// mlx_put_image_to_window
// mlx_get_data_addr :******
//
// mlx_destroy_image
// mlx_get_color_value
// mlx_xpm_to_image
// mlx_xpm_file_to_image
// xml_png_file_to_image

// mlx_pixel_put
// mlx_string_put

// mlx_loop
// mlx_key_hook
// mlx_mouse_hook
// mlx_expose_hook



typedef struct s_checker
{
    bool    no;
    bool    so;
    bool    we;
    bool    ea;
    bool    f;
    bool    c;
}               t_checker;

typedef struct s_image
{
    // mlx_get_data_addr
    // mlx_new_image
    void        *img;   //img to use
    int			type;   
	char		*addr;
    int         endian; //(0-1) value to choose color in pixel
    int         size_line;  //bite to save a line for image in memory

}               t_image;

typedef struct s_texture
{
    t_image     image[4];
    int         rgb_f[3];
    int         rgb_c[3];
}				t_texture;

typedef struct s_map
{
    int         max_x;
    int         max_y;
    char        **map;
}               t_map;

typedef struct s_cub
{
    void        *mlx;
    void        *win;
    t_checker   *checker;
    t_texture   *texture;
    t_map       map;
    t_image     *img;
}               t_cub;

#endif