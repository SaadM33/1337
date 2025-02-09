NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS =  -g -Wall -Werror -Wextra 
X11FLAGS = -lXext -lX11 -lm

SRCS = so_long.c map_parser.c validation.c validation2.c render.c game_logic.c
SRCS_BONUS = game_logic_bonus.c  map_parser_bonus.c  render_bonus.c  so_long_bonus.c validation2_bonus.c  validation_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

fresh : all clean clearscr

bresh : bonus clean clearscr

clearscr:
	clear


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(X11FLAGS) $(OBJS) $(LIBFT) minilibx-linux/libmlx* -o $@

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
	$(CC) $(CFLAGS)$(X11FLAGS) $(OBJS_BONUS) $(LIBFT) minilibx-linux/libmlx* -o $(BONUS)

.PHONY: all clean fclean re bonus