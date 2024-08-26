CC = gcc
CFLAGS = -Wextra -Wall -Werror
LFLAGS = -L. -lft
MLX = -L ./mlx -lmlx -framework OpenGL -framework Appkit
AR = ar rcs

NAME = so_long

P_SRC = so_long.c\
		map_check.c\
		mlx_main.c\
		one_wall_line.c\
		print_image.c\
		so_long_main.c\
		key_press.c

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