
# ifndef CUB3D_H
#define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "structures.h"
# include "functions.h"

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WWIDTH 1280
# define WHEIGHT 720
# define COLOUR_MAP_WALL 0x000000
# define COLOUR_MAP_FLOOR 0xff0000
// 1280:720 (16:9)
// 1280:960 (4:3)

enum e_texture
{
    NO = 1,
    SO,
    WE,
    EA
    // F,
    // C
};

#endif