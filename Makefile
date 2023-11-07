# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:08:21 by dreis-ma          #+#    #+#              #
#    Updated: 2023/11/07 14:29:15 by dmanuel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
DEPS = libft/libft.a minilibx-linux/libmlx.a

SRC = src/main.c src/validate_file.c src/validate_file_utils.c \
src/validate_map.c src/map_cleanup.c src/init.c

OBJ = $(SRC:.c=.o)

NAME = cub3D

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libft
