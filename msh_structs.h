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

typedef struct s_tokenized
{
	t_c_char	*str;
	t_token		token;
}	t_tokenized;

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
}	t_cmd;

typedef struct s_parse_arg __attribute__((deprecated))	t_parse_arg;
typedef struct s_minishell __attribute__((deprecated))	t_minishell;

#endif
