#include "cub3d.h"

int    check_wall(t_map *map, char **m, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] == '0'\
                || m[i][j] == 'E' || m[i][j] == 'W' || m[i][j] == 'S' || m[i][j] == 'N')
            {
                if (i == 0 || j == 0 || i == map->height || !m[i][j + 1])
                    return (1);
            }
            else if (m[i - 1][j] == ' ' || m[i + 1][j] == ' '\
                || m[i][j - 1] == ' ' || m[i][j + 1] == ' ')
                return (1);
        }
    }
    return (0);
}

void    read_set_map(int fd, t_cub *cub, char **tmp)
{
    int     i;
    char    *line;
    char    *str;

    i = 0;
    line = NULL;
    while (i < cub->map.height + 1)
    {
        line = get_next_line(fd);
        if (!line)
            print_error("gnl error: read_set_map", cub);
        str = (char *)malloc(sizeof(char) * (cub->map.width + 1));
        if (!str)
            print_error("malloc error: read_set_map", cub);
        ft_memset(str, ' ', cub->map.width);
        str[cub->map.width + 1] = '\0';
        ft_strcpy(str, line);
        tmp[i] = str;
        free(line);
        line = NULL;
        i++;        
    }
}

void    read_til_start(int fd, t_cub *cub)
{
    // read til map start
}

void    dup_map(t_cub *cub, char *filename)
{
    char **tmp;
    int fd;

    if (cub->map.start == 0)
        print_error("map not found", cub);
    if (cub->player.status == 0)
        print_error("player not found", cub);
    cub->map.height = cub->map.mcount - cub->map.start;
    tmp = (char **)malloc(sizeof(char *) * (cub->map.height + 2));
    if (!tmp)
        print_error("map temp malloc error", cub);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        print_error("dup map file open error", cub);
    read_til_start(fd, cub);
    read_set_map(fd, cub, tmp);
    tmp[cub->map.height + 1] = 0;
    cub->map.map = tmp;
    if(check_wall(&cub->map, cub->map.map, cub))
        print_error("map error: opened wall", cub);
    close(fd);
}