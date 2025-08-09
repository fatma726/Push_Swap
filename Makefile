# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 18:59:46 by fatmtahmdab       #+#    #+#              #
#    Updated: 2025/08/09 18:59:48 by fatmtahmdab      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		main.c \
			commands1.c \
			commands2.c \
			commands3.c \
			utils.c \
			utils2.c \
			parse.c \
			sort.c \
			sort2.c \
			sort3.c
SRCS_B =	checker.c \
			parse.c \
			commands1.c \
			commands2.c \
			commands3.c \
			utils2.c \
			utils.c
FT_SRC =	libft
SRCS_GNL =	get_next_line/get_next_line.c

OBJS =		${SRCS:.c=.o}
OBJS_B =	${SRCS_B:.c=.o}
OBJ_GNL =	${SRCS_GNL:.c=.o}

NAME =		push_swap
NAME_B =	checker

CC =		clang
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror
FTFLAGS =	libft/libft.a

.c.o:
			${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${FT_SRC}
			${CC} -o ${NAME} ${OBJS} ${FTFLAGS}

${NAME_B}:	${OBJ_GNL} ${OBJS_B}
			make -C ${FT_SRC}
			${CC} -o ${NAME_B} ${OBJ_GNL} ${OBJS_B} ${FTFLAGS}

clean:
			${RM} ${OBJS} ${OBJS_B} ${OBJ_GNL}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

all:		${NAME}

bonus:		${NAME_B}

.PHONY: clean, fclean, re, all, bonus
