
# ifndef STRUCTURES_H
#define STRUCTURES_H

#include "cub3d.h"

# define WWIDTH 1280
# define WHEIGHT 720

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
	int		    *data;      // return address of the created image by mlx_get_data_addr
    int         **img_arr;
    int         buffer[WHEIGHT][WWIDTH];
    int         bpp;        // bits_per_pixel: number of bits to express the color of the pixel
    int         endian;     //(0-1) value to choose color in pixel
    int         size_line;  //bite to save a line for image in memory
    int         width;
    int         height;
}               t_image;

typedef struct s_raycasting
{
    int         map_x;          // the box of the map we're in
    int         map_y;
    double      sideDist_x;     // length of ray from current position to next x or y-side
    double      sideDist_y;
    double      deltaDist_x;    // length of ray from one x or y-side to next x or y-side
    double      deltaDist_y;
    double      rayDir_x;
    double      rayDir_y;
    double      perpWallDist;
    int         step_x;         // direction to step in x or y-direction (either +1 or -1): (stepX = 1 ↗ & stepX = -1 ↖)
    int         step_y;         // (stepY = 1 ↘ & stepX = -1 ↗)
    int         side;           // was a NS or EW wall hit
    int         line_height;
    int         startPoint;
    int         endPoint;
    int         texture_x;
    int         texture_y;
    double      ratio;
}               t_raycasting;

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
    void            *mlx;
    void            *win;
    t_map           map;
    t_image         img;
    t_player        player;
    t_raycasting    ray;
}               t_cub;

#endif