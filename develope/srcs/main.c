#include "cub3d.h"

int cub_start(char **argv, t_cub *cub)
{
    init_cub(&cub, argv[1]);
    if (file_parser(&cub, argv[1]))
        return (1);
    return (0);
}

int main(int argc, char *argv[])
{
    t_cub cub;

    if (argc < 2)
    {
        print_error("missing map file 😶‍🌫️🫥", NULL);
    }
    else if (argc > 2)
    {
        print_error("too many arguments 🫠", NULL);
    }
    else if (argc == 2 && !check_extension(argv[1]))
    {
        if (cub_start(argv, &cub))
            return (1);
    }
    return (0);
}