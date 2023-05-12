#include "cub3d.h"

int ft_put_pixel(t_image *img, unsigned int colour, int p_x, int p_y)
{
    if (p_y >= img->height || p_x >= img->width || p_x < 0\
     || p_y < 0 || ((p_y * img->width + p_x) >= (img->width * img->height - 1)))
        return (53);
    img->data[p_y * img->width + p_x] = colour;
    return (0);
}

void draw_square(t_cub *cub, int x, int y, int colour)
{
    int i;
    int j;
    int width;
    int height;

    i = x;
    j = y;
    height = 6;
    width = height;
    while (i < width + x)
    {
        j = y;
        while (j < height + y)
        {
            ft_put_pixel(&cub->img, colour, j, i);
            j++;
        }
        i++;
    }
}

int get_colour_minimap(t_map *map, int i, int j)
{
    int colour;

    if (map->map[i][j] == '1')
        colour = COLOUR_MAP_WALL;
    if (ft_strchr("NSEW0", map->map[i][j]))
        colour = COLOUR_MAP_FLOOR;
    return (colour);
}

void init_minimap(t_cub *cub)
{
    int i;
    int j;
    int colour;
    int offset_x;

    // if (!cub->minimap)
    //     return ;
    // offset_x = cub
}

