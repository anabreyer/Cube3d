DIRSRC		= ./srcs/
DIRINC		= ./incs/
DIROBJ		= ./objs/
DIRLIB		= ./libft/
DIRMLX		= ./minilibx-linux/
HEAD		= ./incs/

SRC_PARSER	= parser/check_path.c\
				parser/check_rgb.c\
				parser/parser.c\
				parser/dup_map.c\
				parser/open_read.c

SRC_UTILS	= utils/utils.c

SRC_INIT	= init/init.c\
				init/init2.c

SRC_PLAY	= play/display.c\
				play/routine.c\
				play/paint_draw.c\

SRC_RAY		= raycasting/raycasting.c

SRC_FREE	= free/freeandexit.c

SRC_KEY		= key_control/turn.c\
				key_control/key_action.c\
				key_control/move.c

SRC_BONUS	= minimap/minimap.c

SRCS		= $(SRC_PARSER)
SRCS		+= $(SRC_UTILS)
SRCS		+= $(SRC_INIT)
SRCS		+= $(SRC_PLAY)
SRCS		+= $(SRC_RAY)
SRCS		+= $(SRC_FREE)
SRCS		+= $(SRC_KEY)
SRCS		+= $(SRC_BONUS)
SRCS		+= main.c
ALLSRCS		= $(addprefix $(DIRSRC), $(SRCS))

SAN 		= -fsanitize=leak

OBJS		= $(ALLSRCS:.c=.o)

NAME		= Cub3D
NAME_BONUS	= Cub3D_bonus
NAMELFT		= libft.a
NAMEMLX		= libmlx.a

CC			= gcc
RM			= rm -f

CFLAGS		= -lft -lmlx -lm -lbsd -lX11 -lXext -g -Wextra -Wall -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRMLX} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE}
			cd ${DIRMLX} && ${MAKE}
			${CC} -o ${NAME} -I${DIRINC} -I${DIRMLX} ${OBJS} -L${DIRLIB} -L${DIRMLX} ${CFLAGS}

main:		$(NAME)
			${CC} ${NAME} main.c

all:		$(NAME)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	${OBJS}
			cd ${DIRLIB} && ${MAKE}
			cd ${DIRMLX} && ${MAKE}
			${CC} -o ${NAME_BONUS} -I${DIRINC} -I${DIRMLX} ${OBJS} -L${DIRLIB} -L${DIRMLX} ${CFLAGS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME) $(NAME_BONUS)

ffclean:	fclean
			cd ${DIRLIB} && ${MAKE} fclean
			cd ${DIRMLX} && ${MAKE} clean

ext:
			cd ${DIRLIB} && ${MAKE} re
			cd ${DIRMLX} && ${MAKE} re

re:			fclean all

.PHONY:		all clean fclean re
