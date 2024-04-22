# #################        LINUX

# NAME	=	so_long
# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g3
# MLX		=	minilibx_linux/libmlx.a
# LFT		=	libft/libft.a
# INC		=	-I ./inc -I ./libft -I ./minilibx_linux
# LIB		=	-L ./libft -lft -L ./minilibx_linux -lmlx -lXext -lX11 -lm
# OBJ		=	$(SRC:.c=.o)

# SRC		=	so_long.c\
# 			file.c\
# 			img.c\
# 			keys.c\
# 			map.c\
# 			route.c\

# COLOR_GREEN=\033[0;32m
# COLOR_RED=\033[0;31m
# COLOR_BLUE=\033[0;34m
# COLOR_END=\033[0m

# all:		$(MLX) $(LFT) $(NAME)

# $(NAME):	$(OBJ)
# 			@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
# 			@echo "$(COLOUR_GREEN) [ OK ] | So Long ready! $(COLOUR_END)"

# $(OBJ): %.o: %.c
# 			@$(CC) $(CFLAGS) -c -o $@ $<

# $(MLX):
# 			echo "$(COLOUR_BLUE) [ ... ] | Compiling minilibx.. $(COLOUR_END)"
# 			@make -s -C minilibx_linux
# 			@echo "$(COLOUR_GREEN) [ OK ] | Minilibx ready! $(COLOUR_END)"

# $(LFT):		
# 			@echo "$(COLOUR_BLUE) [ ... ] | Compiling libft.. $(COLOUR_END)"
# 			@make -s -C libft
# 			@echo "$(COLOUR_GREEN) [ OK ] | Libft ready! $(COLOUR_END)"

# clean:
# 			@make -s $@ -C libft
# 			@make -s $@ -C minilibx_linux
# 			@rm -rf $(OBJ)
# 			@echo "$(COLOUR_RED) [ X ] | Object files removed. $(COLOUR_END)"

# fclean:		clean
# 			@make -s $@ -C libft
# 			@rm -rf $(NAME)
# 			@echo "$(COLOUR_RED) [ X ] | Binary file removed. $(COLOUR_END)"

# re:			fclean all

# .PHONY:		all clean fclean re


 ####################   MAC


NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror # -fsanitize=address -g3
MLX			=	./minilibx-mac/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft
LIB			=	-L ./libft -lft -L ./minilibx_mac -lmlx -framework OpenGL -framework AppKit  # -fsanitize=address -g3
OBJ			=	$(SRC:.c=.o)
SRC			=	so_long.c\
				file.c\
				img.c\
				keys.c\
				map.c\
				route.c\

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
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