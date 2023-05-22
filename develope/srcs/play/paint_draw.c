#include "cub3d.h"

void    paint_floor_ceiling(t_cub *cub)
{
    int y;
    int x;
    int floor;
    int ceiling;

    y = 0;
    floor = cub->map.floor;
    // floor = 0x000080;
    ceiling = cub->map.ceiling;
    // ceiling = 0xdc0077;
    while (y < WHEIGHT / 2)
    {
        x = 0;
        while (x < WWIDTH)
        {
            cub->img.buffer[y][x] = ceiling;
            cub->img.buffer[WHEIGHT - y - 1][x] = floor;
            x++;
        }
        y++;
    }
}

void    draw_image(t_cub *cub)
{
    int y;
    int x;

    y = 0;
    while (y < WHEIGHT)
    {
        x = 0;
        while (x < WWIDTH)
        {
            cub->img.data[y * WWIDTH + x] = cub->img.buffer[y][x];
            x++;
        }
        y++;
    }
    init_minimap(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}