#include "cub3d.h"

void ft_free_img(t_cub *cub, t_image *img)
{
    if(img)
    {
        mlx_destroy_image(cub->mlx, img->data);
        free(img);
        img = NULL;
    }
}
void ft_free_img(t_cub *cub)
{
    int i;
    i = 0;
    if (cub->mlx != NULL)
    {
        mlx_destroy_image(cub->mlx, cub->img.data);
        mlx_destroy_window(cub->mlx, cub->win);
        
    }
}