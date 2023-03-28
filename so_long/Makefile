CC			= gcc
CFLAGS		= -Wextra -Wall -Werror -g3
MLX_LINUX_FLAGS	= -lm -lX11 -lXext
NAME		= so_long

MLX_PATH	= ./minilibx-linux/
MLX			= $(MLX_PATH)libmlx.a

SRC_PATH 	= src/
OBJ_PATH 	= obj/

SRC			= checkmap.c \
				display.c \
				draw.c \
				freeandexit.c \
				ft_itoa.c \
				keyboard.c \
				moveplayer.c \
				parsing.c \
				printtexture.c \
				so_long.c \
				stockmap.c \
				utils.c \
				get_next_line.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./inc/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(LIBFT) $(MLX) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_LINUX_FLAGS) -o $(NAME)


$(MLX):
	make -C $(MLX_PATH)

clean:
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
