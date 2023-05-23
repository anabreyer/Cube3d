#include "cub3d.h"

void    calculate_dda(t_raycasting *ray, t_map *map, t_player *player)
{
    int hit;    // was there a wall hit

    hit = 0;
    while (hit == 0)                                // until it hits the wall
    {
                                                    // jump to next map square, OR in x-direction, OR in y-direction
        if (ray->sidedist_x < ray->sidedist_y)      // if the ray hit the x-side wall, side = 0 |
        {
            ray->sidedist_x += ray->deltadist_x;    // map_x : which wall among x-side walls
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else                                        // else the ray hit the y-side wall, side = 1 __
        {
            ray->sidedist_y += ray->deltadist_y;
            ray->map_y += ray->step_y;              // map_x : which wall among x-side walls
            ray->side = 1;
        }
        if (map->map[ray->map_y][ray->map_x] == '1')
            hit = 1;
    }
    // raycasting tutorial page 3!!
    // we need to avoid fisheyed effect (Euclidean distance will give it)
    if (ray->side == 0)                             // if it hits x-side wall
        ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
        // ray->perpwalldist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
    else
        ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
        // ray->perpwalldist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
                                                    // deltadist_x = |(1 / raydir_x)|  
                                            // (side = 0), perpwalldist = DistX / raydir_x 
                                                // perpwalldist = (mapX - posX + (1 - stepX) / 2) / rayDirX
                                                // perpwalldist = xDist / rayDirX
                                            // (side = 1), 
                                                // perpwalldist = (mapY - posY + (1 - stepY) / 2) / rayDirY
                                                    // line_height = height / perpwalldist
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
        wall = player->pos_y + (ray->perpwalldist * ray->raydir_y);
    else
        wall = player->pos_x + (ray->perpwalldist * ray->raydir_x);
    wall = wall - floor(wall);
    ray->texture_x = (int)(wall * (double)64);
    if (ray->side == 0 && ray->raydir_x < 0)
        ray->texture_x = 64 - ray->texture_x - 1;
    if (ray->side == 1 && ray->raydir_y > 0)
        ray->texture_x = 64 - ray->texture_x - 1;
    ray->line_height = (int)(WHEIGHT / ray->perpwalldist);
    ray->startpoint = WHEIGHT / 2 - ray->line_height / 2;
    ray->endpoint = WHEIGHT / 2 + ray->line_height / 2;
    if (ray->startpoint < 0)
        ray->startpoint = 0;
    if (ray->endpoint >= WHEIGHT)
        ray->endpoint = WHEIGHT;
    ray->ratio = 1.0 * 64 / ray->line_height;
    ray->texture_pos = (ray->startpoint - WHEIGHT / 2 + ray->line_height / 2) * ray->ratio;
    
}

void    set_buffer(t_raycasting *ray, t_image *img, int x)
{
    int y;
    int color;

    y = ray->startpoint;
    while (y < ray->endpoint)
    {
        ray->texture_y = (int)ray->texture_pos & (64 - 1);
        if (ray->side == 0)
        {
            // printf("condition test: %d      tex_x:%d   tex_y: %d dir_x: %f dir_y: %f\n", 64 * ray->texture_y + ray->texture_x, ray->texture_x, ray->texture_y, ray->raydir_x, ray->raydir_y);
            if (ray->raydir_x >= 0)
                color = img->img_arr[EA - 1][64 * ray->texture_y + ray->texture_x];
            else
                color = img->img_arr[WE - 1][64 * ray->texture_y + ray->texture_x];
        }
        else if (ray->side == 1)
        {
            if (ray->raydir_y >= 0)
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

    ray->line_height = (int)WHEIGHT / ray->perpwalldist;

    ray->startpoint = WHEIGHT / 2 - ray->line_height / 2;
    ray->endpoint = WHEIGHT / 2 + ray->line_height / 2;
    if (ray->startpoint < 0)
        ray->startpoint = 0;
    if (ray->endpoint >= WHEIGHT)
        ray->endpoint = WHEIGHT - 1;

    if (cub->map.map[ray->map_y][ray->map_x] == '1')
        color = 0x894a87;
    if (ray->side == 1)
        color = color / 2;

    verLine(cub, x, ray->startpoint, ray->endpoint, color);
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