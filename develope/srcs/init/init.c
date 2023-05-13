#include "cub3d.h"

void    init_key(t_key *key)
{
    key->w = 0;
    key->s = 0;
    key->a = 0;
    key->d = 0;
}

void    init_sideDist(t_raycasting *ray, t_player *player)
{
    if (ray->rayDir_x < 0)
    {
        ray->step_x = -1;
        ray->sideDist_x = (player->pos_x - ray->map_x) * ray->deltaDist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->sideDist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltaDist_x;
    }
    if (ray->rayDir_y < 0)
    {
        ray->step_y = -1;
        ray->sideDist_y = (player->pos_y - ray->map_y) * ray->deltaDist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->sideDist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltaDist_y;
    }
}

void    init_ray(t_cub *cub, int x)
{
    double  camera;     // x-coordinate in camera space

    camera = 2 * x / (double)WWIDTH - 1;    // raycasting tutorial page 3
    if (x == (WWIDTH - 1))
        camera = 1.0;
    cub->ray.rayDir_x = cub->player.dir_x + cub->player.plane_x * camera;   // rayDir_x & rayDir_y: direction vector of ray
    cub->ray.rayDir_y = cub->player.dir_y + cub->player.plane_y * camera;
    cub->ray.map_x = (int)cub->player.pos_x;
    cub->ray.map_y = (int)cub->player.pos_y;
    // printf("\n======> PLAYER pos_X: %d, pox_Y: %d\n\n", (int)cub->player.pos_x, (int)cub->player.pos_y);
                                                            // simplified fomula to get deltaDistX,Y : deltaDistX = abs(1 / rayDirX)
    cub->ray.deltaDist_x = fabs(1 / cub->ray.rayDir_x);     // fabs: function to get an absolute value of real numbers  abs: for integar
    cub->ray.deltaDist_y = fabs(1 / cub->ray.rayDir_y);
    init_sideDist(&cub->ray, &cub->player);
}

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
    img->data = NULL;
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
    else if (player->status == WE)
    {
        player->dir_x = -1;
        player->plane_y = -0.66;
    }
    else if (player->status == EA)
    {
        player->dir_x = 1;
        player->plane_y = 0.66;
    }
    player->speed_move = 0.05;
    player->speed_rotate = 0.05;
}
