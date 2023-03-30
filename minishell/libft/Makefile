# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 09:55:30 by aaduan-b          #+#    #+#              #
#    Updated: 2023/03/25 19:24:22 by aaduan-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

OBJ		= ${SRC:.c=.o}

OBJB	= ${SRCB:.c=.o}

CC		= cc

CC_FLAGS	= -Wall -Wextra -Werror

SRC		= ft_bzero.c ft_calloc.c ft_memset.c ft_memchr.c ft_memcpy.c\
		ft_isascii.c ft_memmove.c ft_memcmp.c ft_strdup.c ft_strchr.c ft_strrchr.c\
		ft_strnstr.c ft_toupper.c ft_tolower.c ft_isalnum.c ft_isalpha.c\
		ft_isdigit.c ft_isprint.c ft_strlen.c ft_atoi.c\
		ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c\
		ft_strtolong.c

SRCB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

.c.o:	${CC} ${CC_FLAGS}-c$<-o${<:.c=.o}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

all:	${NAME}

bonus:	${OBJB}
	ar rcs ${NAME} ${OBJB}

clean:
	rm -f ${OBJ} ${OBJB}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all bonus clean fclean re

