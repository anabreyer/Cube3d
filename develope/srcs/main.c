#include "cub3d.h"

int main(int argc, char *argv[])
{
    t_cub cub;

    if (argc < 2)
    {
        print_error("missing map file 🫥", NULL);
    }
    else if (argc > 2)
    {
        print_error("too many arguments 🫠", NULL);
    }
    else if (argc == 2 && !check_extension(argv[1]))
    {
        if (!file_parser(&cub, argv[1]))
        {
            // routine_start(&cub);
            display(&cub);
        }
            return (1);
    }
    return (0);
}