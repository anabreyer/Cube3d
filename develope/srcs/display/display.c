#include "cub3d.h"

int display(t_cub *cub)
{
    create_window(cub, &cub->map);
    go_hooking(cub);
}

int create_window(t_cub *cub, t_map *map)
{
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, map->width, map->height, "Cube3D");
    return (0);
}

int go_hooking(t_cub *cub)
{
    mlx_hook(cub->win, 33, 1L << 17, closebutton, cub);
    mlx_loop(cub->mlx);
    return(0);
}

int	closebutton(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.img);
	exit (0);
	return (0);
}