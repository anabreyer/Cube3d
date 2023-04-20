#include "cub3d.h"

    // bool    no;
    // bool    so;
    // bool    we;
    // bool    ea;
    // bool    f;
    // bool    c;


int pre_parser(t_cub, *cub, char *str)
{
    char *line;
    //open and read by gnl line by line, search NO, SO ... in line, another check functions to skip whitespace and check is it valide file.
    ft_strstr()
}

int check_extension(char *str, t_cub *cub)
{
    int i;

    i = ft_strlen(str);
    if (str[i - 4] == '.' && str[i - 3] == 'c' && str[i - 2] == 'u' && str[i - 1] == 'b')
    {
        i = open(str, O_RDONLY);
        if (i == -1)
            print_error("", cub);
        else
            close (i);
        return (0);
    }
    print_error("", cub);
    return (1);
}