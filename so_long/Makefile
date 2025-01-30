NAME = so_long
BONUS = checker
CC = gcc
CFLAGS =  -g -Wall -Werror -Wextra -lXext -lX11 -lm

SRCS = so_long.c map_parser.c validation.c validation2.c
SRCS_BONUS = 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

fresh : all clean clearscr

clearscr:
	clear

both: all bonus clean

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) minilibx-linux/libmlx* -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

.PHONY: all clean fclean re bonus