CC = cc
CFLAGS = -g -Wall -Werror -Wextra

NAME_S = server
NAME_C = client
BONUS_S = server_bonus
BONUS_C = client_bonus

SRCS_S = server.c
SRCS_C = client.c
SRCS_S_BONUS = server_bonus.c
SRCS_C_BONUS = client_bonus.c

OBJ_C = $(SRCS_C:.c=.o)
OBJ_S = $(SRCS_S:.c=.o)
OBJ_B_C = $(SRCS_C_BONUS:.c=.o)
OBJ_B_S = $(SRCS_S_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME_C) $(NAME_S) 

fresh: all clean clearscr

bresh: bonus clean clearscr

clearscr:
	clear

$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)

bonus: $(BONUS_C) $(BONUS_S)

$(BONUS_S): $(OBJ_B_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B_S) $(LIBFT) -o $(BONUS_S)

$(BONUS_C): $(OBJ_B_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B_C) $(LIBFT) -o $(BONUS_C)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ_C) $(OBJ_S) $(OBJ_B_C) $(OBJ_B_S)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(BONUS_C) $(BONUS_S)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus fresh bresh clearscr
