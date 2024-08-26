# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 21:04:00 by kimhyeyeon        #+#    #+#              #
#    Updated: 2021/07/18 22:29:51 by kimhyeyeon       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror
LFLAGS = -L. -lft
AR = ar rcs

NAME = push_swap

P_SRC = push_swap.c\
		a_to_b.c\
		b_to_a.c\
		error_case.c\
		find_size.c\
		init.c\
		sort_2345.c\
		list.c\
		list2.c\
		command.c\
		command2.c\
		command3.c\

OBJS = $(P_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a ./
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.a
	make fclean -C libft/

clean:
	rm -rf $(OBJS)
	make clean -C libft/

re: fclean all