#include "cub3d.h"

int routine(t_cub *cub)
{
    create_window(cub);
    init_image(&cub->img, cub);
    create_image(cub);
    init_player(&cub->player);
    // cub->img.img = mlx_new_image(cub->mlx, WWIDTH, WHEIGHT);
    // cub->img.data = (int *)mlx_get_data_data(cub->img.img, &cub->img.bpp, &cub->img.size_line, &cub->img.endian);
    // go_hooking(cub);
}