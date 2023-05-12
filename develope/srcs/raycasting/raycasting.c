#include "cub3d.h"

void    calculate_dda(t_raycasting *ray, t_map *map, t_player *player)
{
    int hit;    // was there a wall hit

    hit = 0;
    while (hit == 0)                                // until it hits the wall
    {
                                                    // jump to next map square, OR in x-direction, OR in y-direction
        if (ray->sideDist_x < ray->sideDist_y)      // if the ray hit the x-side wall, side = 0 |
        {
            ray->sideDist_x += ray->deltaDist_x;    // map_x : which wall among x-side walls
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else                                        // else the ray hit the y-side wall, side = 1 __
        {
            ray->sideDist_y += ray->deltaDist_y;
            ray->map_y += ray->step_y;              // map_x : which wall among x-side walls
            ray->side = 1;
        }
        printf("step_x : %d   step_y : %d\n\n", ray->step_x, ray->step_y);
        printf("map_x : %d   map_y : %d\n\n", ray->map_x, ray->map_y);
        if (map->map[ray->map_y][ray->map_x] == '1')
            hit = 1;
    }
    // raycasting tutorial page 3!!
    // we need to avoid fisheyed effect (Euclidean distance will give it)
    if (ray->side == 0)                             // if it hits x-side wall
        ray->perpWallDist = ray->sideDist_x - ray->deltaDist_x;
        // ray->perpWallDist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->rayDir_x;
    else
        ray->perpWallDist = ray->sideDist_y - ray->deltaDist_y;
        // ray->perpWallDist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->rayDir_y;
                                                    // deltaDist_x = |(1 / rayDir_x)|  
                                            // (side = 0), perpWallDist = DistX / rayDir_x 
                                                // perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX
                                                // perpWallDist = xDist / rayDirX
                                            // (side = 1), 
                                                // perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY
                                                    // line_height = height / perpWallDist
}

/*
(mapX - posX + (1 - stepX) / 2) / rayDirX = sideDistX - deltaDistX
therefore,
    perWallDist = sideDistZ - deltaDistX
*/

/*
delta = 1/ray

step = 1
side = (map + 1 - pos) * delta

(map - pos + (1 - 1) / 2) / rayDirX = side - delta
map - pos = (side - delta) * ray
map - pos = ((map + 1 - pos) * 1 / ray * ray) - (1 / ray * ray)
map - pos = map - pos + 1 - 1
map - pos = map - pos

step = -1
side = (pos - map) * delta
(map - pos + (1 - (-1) / 2) / rayDir = side - delta
map - pos + 1 = (side - delta) *ray
map - pos + 1 = ((pos - map) * delta - delta) * ray

if (step = -1)
    ray < 0
map - pos + 1 = ((pos - map) * 1 / ray * ray) - (1 / ray * ray)
map - pos + 1 = -pos + map + 1
*/


// void    set_buffer(t_raycasting *ray, t_image *img, int x)
// {
//     int y;
//     int x;
//     // int color;

//     // y = ray->startPoint;
//     // while (y < ray->endPoint)
//     // {
//     //     if (ray->rayDir_x >= 0)
//     //         color = img->img_arr[EA - 1][64 * ray->tex_y + ray->tex_x];
//     // }
//     y = 0;
//     while (y < WHEIGHT)
//     {
//         x = 0;
//         while (x < WWIDTH)
//         {
//             img
//         }
//     }
// }

// void    set_buffer_base(t_raycasting *ray, t_player *player)
// {
//     double  wall;

//     if (ray->side == 0) // if ray hits x-side wall |
//     {
//         wall = player->pos_x + (ray->perpWallDist)
//     }
// }


void    verLine(t_cub *cub, int x, int y1, int y2, int color)
{
    int tmp;

    tmp = y1;
    while (tmp <= y2)
    {
        mlx_pixel_put(cub->mlx, cub->win, x, tmp, color);
        tmp++;
    }
}

void    base_setting(t_raycasting *ray, t_cub *cub)
{

    int color;
    int x;

    x = 0;
    while (x < WWIDTH)
    {
    // color = 204 << 16 | 255 << 8 | 204;
    ray->line_height = (int)WHEIGHT / ray->perpWallDist;

    ray->startPoint = WHEIGHT / 2 - ray->line_height / 2;
    ray->endPoint = WHEIGHT / 2 + ray->line_height / 2;
    if (ray->startPoint < 0)
        ray->startPoint = 0;
    if (ray->endPoint >= WHEIGHT)
        ray->endPoint = WHEIGHT - 1;


    if (cub->map.map[ray->map_y][ray->map_x] == '1')
        color = 0xFF0000;
    else
        color = 0x123145;
    if (ray->side == 1)
    {
        printf("1\n");
        color = color / 2;
    }
    
    verLine(cub, x, ray->startPoint, ray->endPoint, color);
    x++;
    }
    // if (ray->side == 1)
    //     color /= 2;
    //     // color = 204 << 16 | 255 << 8 | 204;
    // // else
    //     // color = 102 << 16 | 204 << 8 | 204;

    // int x;
    // int y;

    // x = 0;
    // while (x < WWIDTH)
    // {
    //     y = 0;
    //     while (y < WHEIGHT)
    //     {
    //         mlx_pixel_put(cub->mlx, cub->win, x, y, color);
    //         // verLine(x, ray->startPoint, ray->endPoint, color);
    //         y++;
    //     }
    //     x++;
    // }
}

void    raycasting(t_cub *cub)
{
    int x;

    x = 0;
    while (x < WWIDTH)
    {
        init_ray(cub, x);
        calculate_dda(&cub->ray, &cub->map, &cub->player);
        base_setting(&cub->ray, cub);
        // set_buffer_base(&cub->ray, &cub->player);
        // set_buffer_color(&cub->ray, &cub->img, x);
        x++;
    }
}