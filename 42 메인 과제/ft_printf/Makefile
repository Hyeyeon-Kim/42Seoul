NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crs
AR = ar

SRCS = ft_printf.c print_functions.c print_functions2.c other_functions.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean :
	rm -rf ${OBJS} 

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
