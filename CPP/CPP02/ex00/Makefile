
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = ara_3liha_chi_brad_datay
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

fresh: all clean
	clear -x

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

