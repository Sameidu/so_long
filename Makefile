NAME = so_long.a

SRCS =
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBX = -framework OpenGL -framework AppKit -lmlx

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${LIBX} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
				${RM} ${OBJS}

fclean:		${clean}
				${RM} ${OBJS}
re:			fclean all

.PHONY:		all clean fclean re