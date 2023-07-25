NAME = so_long.a

SRCS =
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx/libmlx.a
LIBFT = ./libft/libft.a
RM = rm -f
LIBX = -framework OpenGL -framework AppKit -lmlx


all: ${NAME} make_mlx

make_mlx: 
	make all -C ./minilibx

make_libft: 
	make all -C ./libft

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${MLX} ${LIBX} ${OBJS} -o ${NAME}


clean:
				${RM} ${OBJS}

fclean:		${clean}
				${RM} ${OBJS}
				
re:			fclean all

.PHONY:		all clean fclean re