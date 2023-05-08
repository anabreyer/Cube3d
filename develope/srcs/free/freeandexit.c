#include "cub3d.h"

int	freeandexit(t_cub *cub)
{
    int i;
    i = 0;
    if (cub->mlx != NULL)
    {
        mlx_destroy_image(cub->mlx, cub->img.img);
        mlx_destroy_window(cub->mlx, cub->win);
        while (i < 4)
        {
            free(cub->map.img_path[i]);
            i++;
        }
        mlx_destroy_display(cub->mlx);
        free(cub->mlx);
    }
    freemap(cub);
    // free_img_arr(cub); //seg fault
    exit(0);
}

int	freemap(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.height)
	{
		free(cub->map.map[i]);
		i++;
	}
	if (cub->map.map)
		free(cub->map.map);
	return (0);
}

int	free_img_arr(t_cub *cub)
{
    int	i;

	i = 0;
	while (i < cub->img.height)
	{
		free(cub->img.img_arr[i]);
		i++;
	}
	if (cub->img.img_arr)
		free(cub->img.img_arr);
	return (0);
}

int	closebutton(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.img);
	exit (0);
	return (0);
}

//free cub->map.map
// free cub->img.img_arr
// use free mahrix function