##################        LINUX

 NAME		=	so_long
 CC			=	gcc
 FLAGS		=	-Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
 MLX		=	mlx/minilibx-linux/Makefile.gen
 LFT		=	libft/libft.a
 INC		=	-I ./inc -I ./libft -I ./minilibx
 LIB		=	-L ./libft -lft -L ./minilibx_linux -lmlx -lXext -lX11 -lm #-lbsd
 OBJ		=	$(patsubst src%, obj%, $(SRC:.c=.o))
 SRC		=	so_long.c\
				error.c\
				file.c\
				

 all:		$(MLX) $(LFT) obj $(NAME)

 $(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

 $(MLX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -s -C minilibx_linux
	@echo " [ OK ] | Minilibx ready!"

 $(LFT):		
	@echo " [ .. ] | Compiling libft.."
	@make -s -C libft
	@echo " [ OK ] | Libft ready!"

 obj:
	@mkdir -p obj

 obj/%.o:	src/%.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

 clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ) obj
	@echo "object files removed."

 fclean:	clean
	@make -s $@ -C libft
	@rm -rf $(NAME)
	@echo "binary file removed."

 re:	fclean all

 .PHONY:	all clean fclean re


#  ####################   MAC
# NAME		=	so_long
# CC			=	gcc
# CFLAGS		=	-Wall -Wextra -Werror # -Imlx
# MLX			=	./minilibx-mac/Makefile.gen
# LFT			=	libft/libft.a
# INC			=	-I ./inc -I ./libft #-I ./minilibx_opengl_20191021
# LIB			=	-L ./libft -lft -lmlx -framework OpenGL -framework AppKit  # -g3 -fsanitize=address#-lbsd 
# OBJ			=	$(SRC:.c=.o)
# SRC			=	so_long.c\
# 				error.c\
# 				file.c\
				

# all:		$(MLX) $(LFT) $(NAME)
# $(NAME):	$(OBJ)
# 			$(CC) $(FLAGS) -o $@ $^ $(LIB)

# $(MLX):
# 			@echo " [ .. ] | Compiling minilibx.."
# 			@make -s -C minilibx_mac
# 			@echo " [ OK ] | Minilibx ready!"

# $(LFT):		
# 			@echo " [ .. ] | Compiling libft.."
# 			@make -s -C libft
# 			@echo " [ OK ] | Libft ready!"

# clean:
# 			@make -s $@ -C libft
# 			@rm -rf $(OBJ)
# 			@echo "object files removed."

# fclean:		clean
# 			@make -s $@ -C libft
# 			@rm -rf $(NAME)
# 			@echo "binary file removed."

# re:			fclean all

# .PHONY:		all clean fclean re