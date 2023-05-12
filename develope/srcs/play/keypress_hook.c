#include "cub3d.h"

// int key_press(int key, t_cub *cub)
// {
//     if (key == )
// // Guess, we need another structre for move key press and relese
// // so in this function if the key press turn the move keyword as '1'
// }

// int key_release(int key, t_cub *cub)
// {
// // and here after release turn the keyword as '0' back
//     if (key == )
// }

int	closebutton(t_cub *cub)
{
    if (cub->img.img != NULL)
		mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	exit (0);
	return (0);
}

int loop_game(t_cub *cub)
{
    paint_floor_ceiling(cub);
        draw_image(cub);
    raycasting(cub);
    // draw_image(cub);
    // key_act_hooking(cub);   // the actual action by key hooking start
}

// 02:KeyPress
// 03:KeyRelease
// 04:ButtonPress
// 05:ButtonRelease
// 17:DestroyNotify
// 33:ClientMessage

int go_hooking(t_cub *cub)
{
    mlx_hook(cub->win, 17, 1L << 17, closebutton, cub);
    // mlx_hook(cub->win, 2, 0, &key_press, cub);
    // mlx_hook(cub->win, 3, 0, &key_release, cub);
    mlx_loop_hook(cub->mlx, &loop_game, cub);
    mlx_loop(cub->mlx);
    return(0);
}