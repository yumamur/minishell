#ifndef MSH_STRUCTS_H
# define MSH_STRUCTS_H

# include "typeft.h"

# define MAX_REDIRECTION 256

typedef enum e_token
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	APPEND,
	HEREDOC,
	OR,
	AND
}	t_token;

typedef struct s_tokenized_list
{
	t_c_char				*str;
	t_token					token;
	struct s_tokenized_list	*next;
}	t_tokenzied_list;

typedef struct s_cmd
{
	t_c_char	*cmd;
	t_c_char	**args;
	int			own_fds;
	int			redirection[MAX_REDIRECTION];
}	t_cmd;

struct s_parse_arg
{
	t_c_char	**parsed;
}	__attribute__((deprecated));

typedef struct s_parse_arg							t_parse_arg;
typedef char __attribute__((deprecated))	**t_env;

struct s_minishell
{
	t_env	env;
	int		last_cmd_exit;
}__attribute__((deprecated));

#endif
