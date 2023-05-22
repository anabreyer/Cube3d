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


void    pre_buffer(t_raycasting *ray, t_player *player)
{
    double  wall;

    if (ray->side == 0)
        wall = player->pos_y + (ray->perpWallDist * ray->rayDir_y);
    else
        wall = player->pos_x + (ray->perpWallDist * ray->rayDir_x);
    wall = wall - floor(wall);
    ray->texture_x = (int)(wall * (double)64);
    if (ray->side == 0 && ray->rayDir_x < 0)
        ray->texture_x = 64 - ray->texture_x - 1;
    if (ray->side == 1 && ray->rayDir_y > 0)
        ray->texture_x = 64 - ray->texture_x - 1;
    ray->line_height = (int)(WHEIGHT / ray->perpWallDist);
    ray->startPoint = WHEIGHT / 2 - ray->line_height / 2;
    ray->endPoint = WHEIGHT / 2 + ray->line_height / 2;
    if (ray->startPoint < 0)
        ray->startPoint = 0;
    if (ray->endPoint >= WHEIGHT)
        ray->endPoint = WHEIGHT;
    ray->ratio = 1.0 * 64 / ray->line_height;
    ray->texture_pos = (ray->startPoint - WHEIGHT / 2 + ray->line_height / 2) * ray->ratio;
    
}

void    set_buffer(t_raycasting *ray, t_image *img, int x)
{
    int y;
    int color;

    y = ray->startPoint;
    while (y < ray->endPoint)
    {
        ray->texture_y = (int)ray->texture_pos & (64 - 1);
        if (ray->side == 0)
        {
            // printf("condition test: %d      tex_x:%d   tex_y: %d dir_x: %f dir_y: %f\n", 64 * ray->texture_y + ray->texture_x, ray->texture_x, ray->texture_y, ray->rayDir_x, ray->rayDir_y);
            if (ray->rayDir_x >= 0)
                color = img->img_arr[EA - 1][64 * ray->texture_y + ray->texture_x];
            else
                color = img->img_arr[WE - 1][64 * ray->texture_y + ray->texture_x];
        }
        else if (ray->side == 1)
        {
            if (ray->rayDir_y >= 0)
                color = img->img_arr[SO - 1][64 * ray->texture_y + ray->texture_x];
            else
                color = img->img_arr[NO - 1][64 * ray->texture_y + ray->texture_x];
        }
        img->buffer[y][x] = color;
        ray->texture_pos += ray->ratio;
        y++;
    }
    
    
}

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

void    paint_untextured_wall(t_raycasting *ray, t_cub *cub, int x)
{
    int color;

    ray->line_height = (int)WHEIGHT / ray->perpWallDist;

    ray->startPoint = WHEIGHT / 2 - ray->line_height / 2;
    ray->endPoint = WHEIGHT / 2 + ray->line_height / 2;
    if (ray->startPoint < 0)
        ray->startPoint = 0;
    if (ray->endPoint >= WHEIGHT)
        ray->endPoint = WHEIGHT - 1;

    if (cub->map.map[ray->map_y][ray->map_x] == '1')
        color = 0x894a87;
    if (ray->side == 1)
        color = color / 2;

    verLine(cub, x, ray->startPoint, ray->endPoint, color);
}


void    raycasting(t_cub *cub)
{
    int x;

    x = 0;
    while (x < WWIDTH)
    {
        init_ray(cub, x);
        calculate_dda(&cub->ray, &cub->map, &cub->player);
        // paint_untextured_wall(&cub->ray, cub, x);
        pre_buffer(&cub->ray, &cub->player);
        set_buffer(&cub->ray, &cub->img, x);
        x++;
    }
}