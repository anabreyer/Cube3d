#include "cub3d.h"

    // bool    no;
    // bool    so;
    // bool    we;
    // bool    ea;
    // bool    f;
    // bool    c;



int file_check(t_map *map, t_checker *checker, char *line)
{
    int i;
    int ret;

    i = 0;
    if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3)\
        || !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
        ret = check_path(map, checker, line);
    else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
        ret = check_color(map, checker, line);
    while (ft_isspace(line[i]))
        i++;
    if (line[i] == '0' || line[i] == '1')
    {
        if (!map->texture->img_path[0] || !map->texture->img_path[1] \
            || !map->texture->img_path[2] || !map->texture->img_path[3])
            ret = 1;
        else
            check_map(map, checker, line);
    }
    // ft_strstr();
    return (ret);
}

int file_parser(t_cub *cub, char *filename)
{
    char *line;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error("cannot open file", cub);
    init_map(&cub->map, cub);
    while (42)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (file_check(&cub->map, &cub->checker, line))
            print_error("wrong data in map file", cub);
        free(line);   
        line = NULL;     
    }
    return (0);
    //open and read by gnl line by line, search NO, SO ... in line, another check functions to skip whitespace and check is it valide file.
}

int check_extension(char *filename)
{
    int i;

    i = ft_strlen(filename);
    if (filename[i - 4] == '.' && filename[i - 3] == 'c'\
        && filename[i - 2] == 'u' && filename[i - 1] == 'b')
        return (0);
    else
        print_error("wrong file extension .cub", NULL);
    return (1);
}