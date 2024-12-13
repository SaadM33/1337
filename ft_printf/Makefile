
SRCS = ft_printf.c  ft_print_hex.c  ft_print_ptr.c  ft_print_udi.c

OBJS = $(SRCS:.c=.o)

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME) 

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C libft all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean bonus fclean re