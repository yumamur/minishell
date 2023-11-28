#ifndef MSH_STRUCTS_H
# define MSH_STRUCTS_H

# define MAX_REDIRECTION 256
# define IFS_DEF " "

typedef enum e_token
{
	WORD,			// "ls -la" -> "ls" "-la"
//	VAR_DEF,		// HOME=/home/tatataha123 bundan emin degilim
	PIPE,			// |
	REDIRECT_IN,	// <
	REDIRECT_OUT,	// >
	APPEND,			// >>
	HEREDOC,		// <<
	OR,				// ||
	AND				// &&
}	t_token;

typedef struct e_tokenized_list
{
	t_c_char	*str;
	t_token		token;
	struct t_tokenized_list	*next;
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

struct s_minishell // global struct
{
	t_env	env;
	int		last_cmd_exit;
};

#endif
