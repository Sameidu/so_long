# #################        LINUX

#  NAME		=	so_long
#  CC			=	gcc
#  FLAGS		=	-Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
#  MLX		=	minilibx_linux/Makefile.gen
#  LFT		=	libft/libft.a
#  INC		=	-I ./inc -I ./libft -I ./minilibx_linux
#  LIB		=	-L ./libft -lft -L ./minilibx_linux -lmlx -lXext -lX11 -lm #-lbsd
#  OBJ		=	$(patsubst src%, obj%, $(SRC:.c=.o))
#  SRC		=	so_long.c\
# 				file.c\
# 				img.c\
# 				keys.c\
# 				map.c\
# 				utils.c\
				

#  all:		$(MLX) $(LFT) $(NAME)

#  $(NAME): $(OBJ)
# 	$(CC) $(FLAGS) -o $@ $^ $(LIB)

#  $(MLX):
# 	@echo " [ .. ] | Compiling minilibx.."
# 	@make -s -C minilibx_linux
# 	@echo " [ OK ] | Minilibx ready!"

#  $(LFT):		
# 	@echo " [ .. ] | Compiling libft.."
# 	@make -s -C libft
# 	@echo " [ OK ] | Libft ready!"

#  clean:
# 	@make -s $@ -C libft
# 	@rm -rf $(OBJ) obj
# 	@echo "object files removed."

#  fclean:	clean
# 	@make -s $@ -C libft
# 	@rm -rf $(NAME)
# 	@echo "binary file removed."

#  re:	fclean all

#  .PHONY:	all clean fclean re


 ####################   MAC


NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX			=	./minilibx-mac/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft
LIB			=	-L ./libft -lft -L ./minilibx_mac -lmlx -framework OpenGL -framework AppKit
OBJ			=	$(SRC:.c=.o)
SRC			=	so_long.c\
				file.c\
				img.c\
				keys.c\
				map.c\
				utils.c\

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "$(COLOUR_GREEN) [ OK ] | So Long ready! $(COLOUR_END)"

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(MLX):
			echo "$(COLOUR_BLUE) [ ... ] | Compiling minilibx.. $(COLOUR_END)"
			@make -s -C minilibx_mac
			@echo "$(COLOUR_GREEN) [ OK ] | Minilibx ready! $(COLOUR_END)"

$(LFT):		
			@echo "$(COLOUR_BLUE) [ ... ] | Compiling libft.. $(COLOUR_END)"
			@make -s -C libft
			@echo "$(COLOUR_GREEN) [ OK ] | Libft ready! $(COLOUR_END)"

clean:
			@make -s $@ -C libft
			@make -s $@ -C minilibx_mac
			@rm -rf $(OBJ)
			@echo "$(COLOUR_RED) [ X ] | Object files removed. $(COLOUR_END)"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "$(COLOUR_RED) [ X ] | Binary file removed. $(COLOUR_END)"

re:			fclean all

.PHONY:		all clean fclean re