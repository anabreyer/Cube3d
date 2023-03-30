NAME	= minishell

CC		= clang
CFLAGS	= -Werror -Wextra -Wall -g

SRC_PATH = ./src/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC		= 	execution/execution_1.c execution/execution_2.c execution/execution_3.c \
			enviromental_variables/env.c enviromental_variables/env_2.c \
			utils/error.c utils/free.c utils/initialization.c utils/execution_utils.c\
			builtins/ft_cd.c builtins/ft_unset.c builtins/ft_echo.c builtins/ft_env.c \
			builtins/ft_exit.c builtins/ft_export.c builtins/ft_pwd.c \
			redirection/redirection.c redirection/pipe.c


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH) -I $(LIBFT_PATH) -I$(READLINE_DIR)/include

LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/enviromental_variables
	mkdir -p $(OBJ_PATH)/utils
	mkdir -p $(OBJ_PATH)/builtins
	mkdir -p $(OBJ_PATH)/redirection
	mkdir -p $(OBJ_PATH)/execution

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(READLINE_LIB)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean