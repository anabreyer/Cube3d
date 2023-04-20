#include "cub3d.h"

void init_image(t_image *image)
{
    image->type = 0;
    image->str = NULL;
    image->prev = NULL;
    image->next = NULL;
}

void init_texture(t_texture *texture)
{
    int i;

    i = 0;
    init_image(texture->image);
    while (i < 3)
    {
        texture->rgb_f[i] = 0;
        texture->rgb_c[i] = 0;
        i++;
    }
}

int init_cub(t_cub *cub, char *str)
{
    cub->map = (t_map) * ft_calloc(1, sizeof(t_map));
    if (!cub->map)
        print_error("error: init: failed to allocate map", cub);
    init_map(cub->map);
    cub->mlx = mlx_init();
    if (!cub->mlx)
        print_error("error: init: failed to init mlx", cub);
    cub->image = (t_image) * malloc(sizeof(t_image));
    if (!cub->image)
        print_error("error: init: failed to allocate image", cub);
    
    init_texture();
}

typedef struct s_image
{
    int			type;
	char		*str;
    int         img_width;
    int         img_height;

}               t_image;

typedef struct s_texture
{
    t_image     image[4];
    int         rgb_f[3];
    int         rgb_c[3];
}				t_texture;

typedef struct s_map
{
    int         max_x;
    int         max_y;
    char        **map;
}               t_map;

typedef struct s_cub
{
    void        *mlx;
    void        *win;
    t_checker   *checker;
    t_texture   texture;
    t_map       map;
}               t_cub;
