#include "cub3d.h"

    // bool    no;
    // bool    so;
    // bool    we;
    // bool    ea;
    // bool    f;
    // bool    c;

// int set_pstatus(char c)
// {
//     if (c == 'N')
//         return (N);
//     else if (c == 'S')
//         return (S);
//     else if (c == 'E')
//         return (E);
//     else if (c == 'W')
//         return (W);
//     return (0);
// }

void    check_mapsyntax(t_map *map, t_player *player, char *line, t_cub *cub)
{
    int i;
    char c;

    i = 0;
    while (line[i])
    {
        c = line[i];
        if (c != 'N' && c != 'S' && c != 'E' && c != 'W'\
            && c!= '0' && c != '1' && c != ' ')
            print_error("wrong element on the map", cub);
        else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        {
            if(player->status != 0)
                print_error("more than one players on the map", cub);
            player->status = c;
        }
        i++;
    }
    if (map->width < i)
        map->width = i;
    if (map->start = 0)
        map->start = map->mcount;
}

int file_check(t_map *map, t_player *player, char *line, t_cub *cub)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3)\
        || !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
        ret = check_path(map, line, cub);
    else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
        ret = check_color(map, line, line[0], cub);
    while (ft_isspace(line[i]))
        i++;
    if (line[i] == '0' || line[i] == '1')
    {
        if (!map->texture.img_path[0] || !map->texture.img_path[1] \
            || !map->texture.img_path[2] || !map->texture.img_path[3]\
            || map->texture.rgb_c[0] == -1 || map->texture.rgb_f[0] == -1)
            print_error("something missing or wrong order data in the file", cub);
        else
            check_mapsyntax(map, player, line, cub);
    }
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
    cub->player.status = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        cub->map.mcount++;
        if (file_check(&cub->map, &cub->player, line, cub))
            print_error("wrong data in map file", cub);
        free(line);   
        line = NULL;     
    }
    dup_map(cub, filename);
    close(fd);
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