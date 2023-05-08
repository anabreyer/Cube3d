#include "cub3d.h"



void init_map(t_map *map, t_cub *cub)
{
    int i;

    map->map = NULL;
    map->width = 0;
    map->height = 0;
    map->mcount = 0;
    map->start = 0;
    i = 0;
    while (i < 4)
        map->img_path[i++] = NULL;
    i = 0;
    while (i < 3)
    {
        map->rgb_c[i] = -1;
        map->rgb_f[i] = -1;
        i++;
    }
    map->floor = 0;
    map->ceiling = 0;
    map->minimap = 1;
}

void    init_img_sub(t_image *img, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (i < WHEIGHT)
    {
        j = 0;
        while (j < WWIDTH)
            img->buffer[i][j++] = 0;
        i++;
    }
    img->img_arr = (int **)malloc(4 * sizeof(int *));
    if (!img->img_arr)
        print_error("error: init_img_sub: img_arr malloc failed", cub);
    i = 0;
    while (i < 4)
    {
        img->img_arr[i] = (int *)malloc(sizeof(int) * 64 * 64);
        if (!img->img_arr[i])
            print_error("error: init_img_sub: img_arr malloc2 failed", cub);
        ft_memset(img->img_arr[i], 0, (sizeof(int) * 64 * 64));
        i++;
    }
}

void init_image(t_image *img, t_cub *cub)
{
    img->img = NULL;
    img->addr = NULL;
    img->img_arr = NULL;
    img->bpp = 0;
    img->endian = 0;
    img->size_line = 0;
    init_img_sub(img, cub);
}

void init_player(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = 0;
    if (player->status == NO)
    {
        player->dir_y = -1;
        player->plane_x = 0.66;
    }
    else if (player->status == SO)
    {
        player->dir_y = 1;
        player->plane_x = -0.66;
    }
    else if (player->status == NO)
    {
        player->dir_y = -1;
        player->plane_x = -0.66;
    }
    else if (player->status == NO)
    {
        player->dir_y = 1;
        player->plane_x = 0.66;
    }
}

// int init_cub(t_cub *cub, char *str)
// {
//     cub->map = ft_calloc(1, sizeof(t_map));
//     if (!cub->map)
//         print_error("error: init: failed to allocate map", cub);
//     cub->mlx = mlx_init();
//     if (!cub->mlx)
//         print_error("error: init: failed to init mlx", cub);
//     cub->img = malloc(sizeof(t_image));
//     if (!cub->img)
//         print_error("error: init: failed to allocate image", cub);
//     init_image(&cub->img, cub);
//     cub->player = malloc(sizeof(t_player));
//     if (!cub->player)
//         print_error("error: init: failed to allocate player", cub);
//     init_player(&cub->player, cub);

// }



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
