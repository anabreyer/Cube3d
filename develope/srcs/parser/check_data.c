#include "cub3d.h"

char *get_path(char *line, t_cub *cub)
{
    int fd;
    char *p;

    p = line;
    p += 2;
    while (ft_isspace(*p))
        p++;
    fd = open(p, O_RDONLY);
    if (fd < 0)
        print_error("cannot open texture image file", cub);
    close(fd);
    return (p);
}

int check_path(t_map *map, char *line, t_cub *cub)
{
    char *path;

    path = get_path(line, cub);
    if (!path)
        return (1);
    if (line[0] == 'N' && map->texture->img_path[0] == NULL)
        map->texture->img_path[0] = path;
    else if (line[0] == 'S' && map->texture->img_path[1] == NULL)
        map->texture->img_path[1] = path;
    else if (line[0] == 'W' && map->texture->img_path[2] == NULL)
        map->texture->img_path[2] = path;
    else if (line[0] == 'E' && map->texture->img_path[3] == NULL)
        map->texture->img_path[3] = path;
    else
        print_error("double keyword for the texture file", cub);
    return (0);
}

int check_range_and_set(char *line, t_map *map, t_cub *cub)
{
    int i;

    i = 0;
    while (line[i])
    {
        i += skip_spacei(line + i);
        if (ft_isdigit(line[i]))
        {
            if (!(ft_atoi(line + i) >= 0 && ft_atoi(line + i) <= 255))
                print_error("rgb range error: (0-255)", cub);
            while (ft_isdigit(line[i]))
                i++;
        }
    }
}

int    check_syntax_rgb(char *line, t_map *map, t_cub *cub)
{
    int i;
    int comma;
    int count;

    line += 2;
    i = 0;
    comma = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == ',')
            comma++;
        if (!(ft_isspace(line[i]) || ft_isdigit(line[i]) || line[i] == ','))
            print_error("found non-numeric for rgb", cub);
        if (!ft_digit(line[i]) && ft_digit(line[i + 1]))
            count++;
        i++;
    }
    if (comma != 2 || count > 3)
        return (1);
    return (check_range_and_set(line, map, cub));
}

            
            else
                return (1);
            i += skip_spacei(line + i);
            if (line[i] == ',' && comma += (line[i] == ','))
                i++;
            else if (line[i])
                return (0);


int check_color(t_map *map, char *line, char key, t_cub *cub)
{
    int ret;

    ret = 0;
    line += 2;
    while (ft_isspace(*line))
        line++;
    ret = check_syntax_rgb(line, cub);

    if (key == 'C')
    map->texture->rgb_c = rgb_split(line, ',');
}