# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsong <dsong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 01:29:16 by dsong             #+#    #+#              #
#    Updated: 2022/02/15 01:29:17 by dsong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c src/signal.c src/data.c src/parse.c src/check.c src/list.c src/list2.c src/envp.c src/envp2.c \
		src/error_handling.c src/minishell.c src/redirect.c src/parse2.c src/parse3.c src/pipe.c src/type.c \
		src/redic_and_exec.c src/get_cmd.c src/fd_read_and_write.c src/ft_close.c\
		src/built/ft_cd.c src/built/error_print.c src/built/ft_pwd.c src/built/ft_env.c src/built/ft_echo.c src/built/ft_exit.c \
		src/built/is_built_in.c

OBJS = ${SRCS:.c=.o}
NAME = minishell
cc = gcc
RM = rm -f

MCHECK = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -l readline -L /opt/homebrew/opt/readline/lib
IFLAGS = -I /opt/homebrew/opt/readline/include
LIBFT = -L ./libft -lft


all : ${NAME}
$(NAME) : ${OBJS} 
	@${MAKE} -C ./libft bonus
	${CC} ${CFLAGS} ${LFLAGS} ${IFLAGS} ${SRCS} ${LIBFT} -o ${NAME}
clean :
	@${MAKE} -C ./libft clean
	${RM} ${OBJS}
fclean : clean
	@${MAKE} -C ./libft fclean
	${RM} ${NAME}
re : fclean all