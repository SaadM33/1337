
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = abstract
SRCS = AAnimal.cpp  Brain.cpp  Cat.cpp  Dog.cpp  WrongAnimal.cpp  WrongCat.cpp  main.cpp
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

