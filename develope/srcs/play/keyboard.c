#include "cub3d.h"

int keyboard(int keycode, t_cub *cub)
{
    if (keycode == ESC)
        freeandexit(cub); //seg fault??
    return (0);
}