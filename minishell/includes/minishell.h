/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:16:17 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/18 19:51:32 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

/*     MACROS     */

# ifndef MINISHELL_MACRO
#  define MINISHELL_MACRO
#  define DF 0 // default
#  define SQ 1 // single quotes
#  define DQ 2 // double quotes
#  define OP 3 // opperators (<<, >>, <, >)
#  define PP 4 // pipe
#  define HEREDOC_SIZE 20
# endif

typedef struct s_token
{
	char			*arg;
	int				type;
	int				append;

	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	struct s_token	*list;

	int				in_fd;
	int				out_fd;

	int				skip_cmd;

	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*str;
	char	*cwd;

	t_token	*token_list;

	int		in_save;
	int		out_save;

	t_cmd	*cmd_list;
	int		exit_code;

}	t_data;

/* Signal func */
void	handle_signals(void);
void	sigint_handler(int sig);
void	heredoc_sig_handler(int sig);
int		*get_status(void);

/* Parsing */
int		parser(t_data *data);
int		lexer(t_data *data);
int		syntax_checker(t_data *data, char unmatched_quote);
void	list_to_cmds(t_data *data);

/* redirections and heredoc */
int		handle_redirections(t_data *data, t_cmd *cmd);
int		handle_heredoc(t_data *data, t_cmd *cmd);
int		last_in_redirection(t_cmd *cmd, t_token *node);
int		open_out_files(t_cmd *cmd, t_token *curr, t_data *data, char *name);
int		open_in_files(t_cmd *cmd, t_data *data, t_token *curr, char *name);
int		ft_should_expand(t_token *node);

/* expand and join */
t_token	*ft_expand_and_join(t_token *node, t_data *data,
			int not_expand, int *flag);
char	**ft_split_whitespace(char const *s);
char	*mini_expand(char *token, t_data *data);
void	expand_all(t_data *data);

/* built in functions */
int		is_builtin(t_token *token);
void	do_builtin(t_data *data, t_token *list, int exit_or_not);

int		do_cd(t_data *data, t_token *list);
int		do_echo(t_data *data, t_token *list);
int		do_env(t_data *data);
int		do_exit(t_data *data, t_token *list);
int		do_export(t_data *data, t_token *list);
int		do_pwd(t_data *data);
int		do_unset(t_data *data, t_token *list);

/* env functions */
char	**ft_dupenv(char **env);
int		ft_in_env(char *key, t_data *data);
void	sort_env(char **env);
void	ft_setenv(char ***env, char *key, char *val);
char	*ft_getenv(char *key, t_data *data);
void	ft_remvar(char *key, char ***env);

/* Execution! */
void	exec_single_builtin(t_data *data, t_cmd *cmd);
void	execute_cmd(t_data *data, t_token *list);
void	full_execution(t_data *data);
int		var_end_index(char *str);
int		var_index(char *str);
int		has_var(char *str);

/* Linked list stuff*/
void	add_cmd_node(t_cmd **head, t_token *list);
void	add_token_node(t_token **head, char *arg, int type, int append);
void	remove_token(t_token **head, t_token *node);

/* Print list stuff */
void	print_token_list(t_token *lst);
void	print_cmd_list(t_cmd *head);

/* error */
void	ft_error(char *str);
void	ft_error2(char *str1, char *str2);
void	ft_error3(char *str1, char *str2, char *str3);
void	ft_error4(char *str1, char *str2, char *str3, char *str4);

/* clean-up functions */
void	ft_free_table(char **table);
void	free_token_list(t_token **head);
void	free_cmd_list(t_cmd **head);

/* general */
t_data	*get_data(void);
int		get_fd(int	*ptr);
int		*get_status(void);
int		ft_isspace(char c);
char	*ft_strjoin3(char *str1, char *middle, char *str2);
void	free_appended_nodes(t_token **head, t_token *node);

/* tmp for now */
void	close_prev_fd(t_cmd *cmd, int in_or_out);
int		ft_heredoc(t_token *node, t_cmd *cmd, t_data *data);

/* lexer shmelter */
int		ft_isquote(char c);
int		ft_isoperator(char c);
int		ft_isdelimiter(char c);

#endif
