#include "cub3d.h"

int keyboard(int keycode, t_cub *cub)
{
    if (keycode == ESC)
        freeandexit(cub); 
    return (0);
}