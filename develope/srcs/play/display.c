#include "cub3d.h"

int go_hooking(t_cub *cub)
{
    mlx_hook(cub->win, 33, 1L << 17, closebutton, cub);
    mlx_loop(cub->mlx);
    return(0);
}

void    set_img_arr(t_cub *cub, int i)
{
    int x;
    int y;

    y = 0;
    while (y < cub->img.height)
    {
        x = 0;
        while (x < cub->img.width)
        {
            cub->img.img_arr[i][cub->img.width * y + x] = cub->img.addr[cub->img.height * y + x];
            // printf("%d ", cub->img.img_arr[i][cub->img.width * y + x]);
            // printf("x: %d\n", x);
            x++;
        }
        // printf("y: %d\n", y);
        y++;
    }
}

void    create_image(t_cub *cub)
{
    int     i;
    char    *path;

    i = 0;
    while (i < 4)
    {
        path = cub->map.img_path[i];
        printf("path: %s\n", path);
        cub->img.img = mlx_xpm_file_to_image(cub->mlx, path, &cub->img.width, &cub->img.height);
        // wood.xpm: 64 * 64
        printf("cub->img.width : %d  \n", cub->img.width);
        if (cub->img.width != 64 || cub->img.height != 64 || !cub->img.img)
            print_error("error: create_image: load xpm file to image got an error", cub);
        cub->img.addr = (int *)mlx_get_data_addr(cub->img.img, &cub->img.bpp, &cub->img.size_line, &cub->img.endian);
        // When I assign addr value as char* is has segfault, But I don't know why
        printf("addr : i: %d %ls\n", i, cub->img.addr);
        set_img_arr(cub, i);
        // mlx_destroy_image(cub->mlx, cub->img.img);
        i++;
    }
}

int create_window(t_cub *cub)
{
    cub->mlx = mlx_init();
    if (!cub->mlx)
        print_error("error: create_window: failed to init mlx", cub);
    cub->win = mlx_new_window(cub->mlx, WWIDTH, WHEIGHT, "Cub3D");
    if (!cub->win)
        print_error("error: create_window: failed to create window", cub);
    return (0);
}
