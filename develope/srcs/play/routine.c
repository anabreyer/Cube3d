#include "cub3d.h"

int routine(t_cub *cub)
{
    create_window(cub);
    init_image(&cub->img, cub);
    create_image(cub);
    init_player(&cub->player);
    init_minimap(cub);
    mlx_put_image_to_window(cub->mlx,
		cub->win, cub->img.img, 0, 0);
    go_hooking(cub);
}