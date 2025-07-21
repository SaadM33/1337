CC = cc
CFLAGS = -g -Wall -Werror -Wextra
PTHREAD = -pthread

NAME = philo

SRCS = main.c  utils.c  utils_philo.c utils_input.c 


OBJS = $(SRCS:.c=.o)


all: $(NAME)

fresh: all clean clearscr


clearscr:
	clear

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)



clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) 

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re  fresh clearscr