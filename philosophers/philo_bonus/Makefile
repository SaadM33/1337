CC = cc
CFLAGS = -g -Wall -Werror -Wextra
PTHREAD = -pthread

NAME = philo
BONUS = philo_bonus

SRCS = main.c  utils.c  utils_philo.c utils_input.c 


SRCS_BONUS = main_bonus.c  init_bonus.c   utils_bonus.c  routine_bonus.c   cleanup_bonus.c
              

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


all: $(NAME)

fresh: all clean clearscr

bresh: bonus clean clearscr

clearscr:
	clear

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJS_BONUS) -o $(BONUS)


clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus fresh bresh clearscr