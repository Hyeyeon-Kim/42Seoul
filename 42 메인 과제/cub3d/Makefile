# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 22:16:06 by kimhyeyeon        #+#    #+#              #
#    Updated: 2022/03/23 22:40:25 by kimhyeyeon       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror -g
LFLAGS = -L. -lft
MLX = -L ./mlx -lmlx -framework OpenGL -framework Appkit
AR = ar rcs

NAME = cub3D

P_SRC = src/cub3d.c \
		src/cub3d_utiles.c\
		src/mlx_loop_main.c\
		src/move_directions.c\
		src/key_press.c\
		src/map_src/get_data.c \
		src/map_src/dfs.c \
		src/map_src/map_error_check.c\
		src/map_src/error_check_map_components.c\
		src/map_src/read_cub_file.c \
		src/raycasting/raycast.c \
		src/raycasting/raycast2.c \
		src/raycasting/draw.c \

OBJS = $(P_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a ./
	make -C ./mlx
	$(CC) $(CFLAGS) $(LFLAGS) $(MLX) $^ -o $@ 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.a
	make fclean -C libft/
	make clean -C mlx/

clean:
	rm -rf $(OBJS)
	make clean -C libft/
	make clean -C mlx/

re: fclean all