
SRCS	= main.cpp Type.cpp A.cpp B.cpp C.cpp Base.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= ex02

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDE	= none
HEADER	= Type.hpp C.hpp B.hpp A.hpp Base.hpp

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
