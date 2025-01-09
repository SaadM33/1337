NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS =  -Wall -Werror -Wextra

SRCS = 1-rev_rotate.c  2-rotate_push.c  3-swap.c  main.c  sort_algo.c  utils_input.c  utils_input2.c  utils_sort2.c  utils_sort.c
SRCS_BONUS = checker_bonus.c get_next_line.c get_next_line_utils.c 1-rev_rotate.c  2-rotate_push.c  3-swap.c  sort_algo.c  utils_input.c  utils_input2.c  utils_sort2.c  utils_sort.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

both: all bonus clean

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus