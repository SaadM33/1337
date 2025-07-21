
CC = cc

FLAGS = -Wall -Werror -Wextra -g

NAME = minishell



SRC_PATH =	src

OBJ_PATH =	obj

LIB_PATH =	libft



LIB_NAME =	libft.a

SRC_NAME =	main.c \
			parsing/parser.c \
			parsing/lexer.c \
			parsing/lexer_utils.c \
			parsing/syntax_checker.c \
			parsing/expand_and_join.c \
			parsing/expand_all.c \
			parsing/heredoc.c \
			parsing/redirection.c \
			parsing/redirection_utils.c \
			parsing/ft_split_whitespace.c \
			utils/signals.c \
			utils/errors.c \
			utils/linked_list.c \
			utils/linked_cmd.c \
			utils/general.c \
			utils/envirenment.c \
			built_in/ft_cd.c \
			built_in/ft_echo.c \
			built_in/ft_env.c \
			built_in/ft_exit.c \
			built_in/ft_export.c \
			built_in/ft_pwd.c \
			built_in/ft_unset.c \
			exec/execution.c \
			exec/run_builtin.c \
			exec/run_cmd.c 
			
OBJ_NAME = $(SRC_NAME:.c=.o)



INC =	libft/includes/libft.h

SRC =	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ =	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIB =	$(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC_FLAGS =	-Iincludes -Ilibft/includes/



all: $(NAME)

val: $(NAME)
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

run: $(NAME)
	./$(NAME)

fresh: all clean
	clear

# ----------------------------------- #


$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) $(OBJ) $(LIB) -lreadline  -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAGS)
	@echo $<
	
clean:
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re val run fresh 
