#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef char	**t_env;
typedef char	**t_cmd_args;

typedef struct e_redirection
{
	int	rd_from;
	int	rd_to;
	int	append : 1;
}	t_redirection;

typedef struct s_cmd_string
{
	t_cmd_args		args;
	t_redirection	*redirect;
	t_env			env;
}	t_cmd_string;

struct s_minishell
{
	t_env	*env;
	int		last_cmd_exit;
};

#endif
