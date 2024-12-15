
SRCS = 

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $@

$(LIBFT):
	make -C libft all

bonus: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean bonus fclean re