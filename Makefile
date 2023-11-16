# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:08:21 by dreis-ma          #+#    #+#              #
#    Updated: 2023/11/16 12:13:58 by dmanuel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
DEPS = libft/libft.a minilibx-linux/libmlx.a

SRC = src/main.c src/validate_file.c src/validate_file_utils.c \
src/validate_file_utils_2.c src/validate_map.c src/validate_map_utils.c \
src/map_cleanup.c src/init.c src/ray.c src/color_draw.c src/color_utils.c \
src/key_handle.c src/exit.c src/movement.c src/rotate.c \
src/movement.c

OBJ = $(SRC:.c=.o)

NAME = cub3D

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libft
	$(MAKE) re -C ./minilibx-linux
