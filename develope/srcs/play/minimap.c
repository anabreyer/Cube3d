#include "cub3d.h"

int ft_put_pixel(t_image *img, unsigned int colour, int x, int y)
{
    char *dest;

    if (y >= img->height || x >= img->width || x < 0\
     || y < 0 || ((y * img->width + x) >= (img->width * img->height - 1)))
        return (53);

    // dest = img->addr + (y * img->width + x * (img->bpp / 8));
    // *(unsigned int *)dest = colour;
    img->addr[y * img->width + x] = colour;
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
    height = MINIMAP_SIZE;
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

    if (!cub->map.minimap)
        return ;
    offset_x = cub->map.width / 2- (ft_strlen(cub->map.map[0]) * MINIMAP_SIZE) / 2;
    i = 0;
    while (i < cub->map.height)
    {
        j = 0;
        while (cub->map.map[i][j] != '\0')
        {
            colour = get_colour_minimap(&cub->map, i, j);
            draw_square(cub, i * MINIMAP_SIZE, offset_x + j * MINIMAP_SIZE, colour);
            j++;
        }
        i++;
    }
    //draw_square(cub, )
}

