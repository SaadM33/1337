CC = cc
CFLAGS =  -g -Wall -Werror -Wextra

NAME_S =  	server
NAME_C =	client
BONUS_S =	server_bonus
BONUS_C =	client_bonus


SRCS_S = server.c
SRCS_C = client.c
SRCS_S_BONUS =	server_bonus.c
SRCS_C_BONUS =	client_bonus.c


OBJ_C = ${SRCS_C:.c=.o}
OBJ_S = ${SRCS_S:.c=.o}
OBJ_B_C = ${SRCS_C_BONUS:.c=.o}
OBJ_B_S = ${SRCS_S_BONUS:.c=.o}



all: $(NAME_C) $(NAME_s) 

fresh : all clean clearscr

bresh : bonus clean clearscr

clearscr:
		clear

$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $@

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $@


LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(LIBFT):
	make -C $(LIBFT_PATH)



clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean


fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_PATH) fclean


re: fclean all


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_C) $(BONUS_S)

$(BONUS_S): $(OBJ_B_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $@

$(BONUS_C): $(OBJ_B_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B_C) $(LIBFT) -o $@

.PHONY: all clean fclean re bonus