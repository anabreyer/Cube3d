#include "cub3d.h"

int routine(t_cub *cub)
{
    create_window(cub);
    init_image(&cub->img, cub);
    create_image(cub);
    init_player(&cub->player);
    go_hooking(cub);
}