DIRSRC		= ./srcs/
DIRINC		= ./incs/
DIROBJ		= ./objs/
DIRLIB		= ./libft/
DIRMLX		= ./minilibx-linux/
# DIRBMP		= ./libbmp/
DIRINIT		= ./init/
DIRUTIL		= ./utils/
DIRPARS		= ./parser/
DIRPLAY		= ./play/
DIRFREE		= ./free/
HEAD		= ./incs/

SRC_PARSER	= parser/check_data.c\
				parser/parser.c\
				parser/dup_map.c

SRC_UTILS	= utils/utils.c

SRC_INIT	= init/init.c

SRC_PLAY	= play/display.c\
				play/routine.c\
				play/keyboard.c

SRC_FREE	= free/freeandexit.c

SRCS		= $(SRC_PARSER)
SRCS		+= $(SRC_UTILS)
SRCS		+= $(SRC_INIT)
SRCS		+= $(SRC_PLAY)
SRCS		+= $(SRC_FREE)
SRCS		+= main.c
ALLSRCS		= $(addprefix $(DIRSRC), $(SRCS))

SAN 		= -fsanitize=leak

OBJS		= $(ALLSRCS:.c=.o)

NAME		= Cub3D
NAMELFT		= libft.a
NAMEMLX		= libmlx.a
# NAMEBMP		= libbmp.a

CC			= gcc
RM			= rm -f

CFLAGS		= -lft -lmlx -lm -lbsd -lX11 -lXext

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRMLX} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE}
			cd ${DIRMLX} && ${MAKE}
			${CC} -o ${NAME} -I${DIRINC} -I${DIRMLX} ${OBJS} -L${DIRLIB} -L${DIRMLX} ${CFLAGS}

main:		$(NAME)
			${CC} ${NAME} main.c

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

ffclean:	fclean
			cd ${DIRLIB} && ${MAKE} fclean
			cd ${DIRMLX} && ${MAKE} clean

ext:
			cd ${DIRLIB} && ${MAKE} re
			cd ${DIRMLX} && ${MAKE} re

re:			fclean all

.PHONY:		all clean fclean re
