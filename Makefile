# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 19:15:17 by smeixoei          #+#    #+#              #
#    Updated: 2023/07/25 19:15:19 by smeixoei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRCS =
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx/libmlx.a
#LIBFT = ./libft/libft.a
RM = rm -f
LIBX = -framework OpenGL -framework AppKit -lmlx


all: ${NAME} make_mlx

make_mlx: 
	make all -C ./minilibx

# make_libft: 
#	make all -C ./libft

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${MLX} ${LIBX} ${OBJS} -o ${NAME}


clean:
				${RM} ${OBJS}
				make clean -C ./minilibx
				make clean -C ./libft

fclean:		${clean}
				${RM} ${OBJS}
				make clean -C ./minilibx
				make fclean -C ./libft
				
re:			fclean all

.PHONY:		all clean fclean re