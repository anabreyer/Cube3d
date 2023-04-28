#include "cub3d.h"


//test~~~~~~~~~~~~~~~~~~~~~~~~!!!!

int init_texture(t_texture *texture, t_cub *cub)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        texture->img_path[i] = NULL;
    }
    i = 0;
    while (i < 3)
    {
        texture->rgb_f[i] = -1;
        texture->rgb_c[i] = -1;
        i++;
    }
    texture->floor = 0;
    texture->ceiling = 0;
}

void init_map(t_map *map, t_cub *cub)
{
    map->map = NULL;
    map->width = 0;
    map->height = 0;
    init_texture(&map->texture, cub);
}

void init_image(t_image *img, t_cub *cub)
{
    img->img = NULL;
    img->addr = NULL;
    img->bpp = 0;
    img->endian = 0;
    img->size_line = 0;
}

void init_player(t_player *player, t_cub *cub)
{
    player->status = 0;
}

int init_cub(t_cub *cub, char *str)
{
    cub->map = ft_calloc(1, sizeof(t_map));
    if (!cub->map)
        print_error("error: init: failed to allocate map", cub);
    cub->mlx = mlx_init();
    if (!cub->mlx)
        print_error("error: init: failed to init mlx", cub);
    cub->img = malloc(sizeof(t_image));
    if (!cub->img)
        print_error("error: init: failed to allocate image", cub);
    init_image(&cub->img, cub);
    cub->player = malloc(sizeof(t_player));
    if (!cub->player)
        print_error("error: init: failed to allocate player", cub);
    init_player(&cub->player, cub);

}



// typedef struct s_image
// {
//     // mlx_get_data_addr
//     // mlx_new_image
//     void        *img;   //img to use  
// 	char		*addr;
//     int         bpp;
//     int         endian; //(0-1) value to choose color in pixel
//     int         size_line;  //bite to save a line for image in memory

// }               t_image;

// typedef struct s_texture
// {
//     char        *img_path[4];
//     int         rgb_f[3];
//     int         rgb_c[3];
// }				t_texture;

// typedef struct s_map
// {
//     int         map_x;
//     int         map_y;
//     char        **map;
//     t_texture   *texture;
// }               t_map;

// typedef struct s_cub
// {
//     void        *mlx;
//     void        *win;
//     t_checker   *checker;
//     t_map       *map;
//     t_image     *img;
// }               t_cub;
