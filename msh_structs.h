#ifndef MSH_STRUCTS_H
# define MSH_STRUCTS_H

# include "typeft.h"

# define MAX_REDIRECTION 256
# define IFS_DEF " "

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

typedef struct s_redirection
{
	int	fd[2];
}	t_redirection;

typedef struct s_cmd
{
	t_c_char		*cmd;
	t_c_char		**args;
	t_redirection	own_fds;
	t_redirection	redirection[MAX_REDIRECTION];
}	t_cmd;

typedef char	**t_env;

struct s_minishell
{
	t_env	env;
	int		last_cmd_exit;
};

#endif
