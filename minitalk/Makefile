NAME = client  server
BONUS = client_bonus  server_bonus
CC = cc
CFLAGS =  -g -Wall -Werror -Wextra

SRCS = 
SRCS_BONUS = 

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