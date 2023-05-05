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

int check_path(char *line, t_cub *cub)
{
    char *path;

printf("chaeck_path: line: %s\n", line);
    path = get_path(line, cub);
    printf("PATH: check_PATH: %s\n", path);
    if (!path)
        return (1);
    if (line[0] == 'N' && cub->map.img_path[0] == NULL)
    {   cub->map.img_path[0] = ft_strdup(path);
        printf("GOTIN?_[N]: %s \n",cub->map.img_path[0]);
    }
    else if (line[0] == 'S' && cub->map.img_path[1] == NULL)
    {
        cub->map.img_path[1] = ft_strdup(path);
        printf("GOTIN?_[S]: %s \n",cub->map.img_path[1]);
    }
    else if (line[0] == 'W' && cub->map.img_path[2] == NULL)
    {
        cub->map.img_path[2] = ft_strdup(path);
        printf("GOTIN?_[W]: %s \n",cub->map.img_path[2]);
    }
    else if (line[0] == 'E' && cub->map.img_path[3] == NULL)
    {
        cub->map.img_path[3] = ft_strdup(path);
        printf("GOTIN?_[E]: %s \n",cub->map.img_path[3]);
    }
    else
        print_error("double keyword for the texture file", cub);
    return (0);
}

int check_range(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {   
        while (line[i] && (ft_isspace(line[i]) || line[i] == ','))
            i++;
        if (ft_isdigit(line[i]))
        {
            if (!(ft_atoi(line + i) >= 0 && ft_atoi(line + i) <= 255))
                return (1);
            while (ft_isdigit(line[i]))
                i++;
        }
    }
    return (0);
}

int    check_syntax_rgb(char *line, t_cub *cub)
{
    int i;
    int comma;
    int count;

    i = 0;
    comma = 0;
    count = 0;
    while (line && line[i])
    {
        if (line[i] == ',')
            comma++;
        if (!ft_isspace(line[i]) && !ft_isdigit(line[i]) && line[i] != ',')
            print_error("found non-numeric for rgb", cub);
        if (!ft_isdigit(line[i]) && ft_isdigit(line[i + 1]))
            count++;
        i++;
    }
    if (comma != 2 || count > 3)
        return (1);
    return (check_range(line));
}

void    rgb_split(char *line, int rgb[3], char sep)
{
    int i;

    i = 0;
    while (line && *line && i < 3)
    {
        while (*line && (ft_isspace(*line) || *line == ','))
            line++;
        rgb[i] = ft_atoi(line);
        i++;
        while (*line && ft_isdigit(*line))
            line++;
    }
}

int check_color(char *line, char key, t_cub *cub)
{
    int ret;
    int i;

    ret = 0;
    line += 2;
    while (ft_isspace(*line))
        line++;
    if(check_syntax_rgb(line, cub))
        print_error("rgb range error: (0-255)", cub);
    i = 0;
    if (key == 'C')
        rgb_split(line, cub->map.rgb_c, ',');
    else if (key == 'F')
        rgb_split(line, cub->map.rgb_f, ',');
    return (ret);
}