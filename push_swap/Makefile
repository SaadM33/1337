NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = 1-rev_rotate.c  2-rotate_push.c  3-swap.c  main.c  sort_algo.c  utils_input.c  utils_sort2.c  utils_sort.c
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME) clean

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re