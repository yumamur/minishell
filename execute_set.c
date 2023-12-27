#include <unistd.h>
#include "env_util.h"
#include "error.h"
#include "msh_structs.h"
#include "pt_util.h"
#include "libft/libft.h"
#include "lpc.h"

void	*join_slash(void *str);
int		count_args(t_list *tokens);
void	assign_files_to_open(t_list *lst, t_tokenized to_open[3]);
int		open_file_redirect(t_tokenized *tkn);

char	**set_args(t_list *tokens)
{
	char		**args;
	int			arg_ct[2];
	t_tokenized	*ptr;

	arg_ct[0] = count_args(tokens);
	args = malloc(sizeof(char *) * (arg_ct[0] + 1));
	lpc_export(args, arr_free, NULL);
	if (!args)
		return (NULL);
	arg_ct[1] = 0;
	while (arg_ct[1] < arg_ct[0])
	{
		ptr = tokens->content;
		if (ptr->token == CMD || ptr->token == WORD)
		{
			args[arg_ct[1]] = ft_strdup(ptr->str);
			++arg_ct[1];
		}
		tokens = tokens->next;
	}
	args[arg_ct[1]] = NULL;
	return (args);
}

char	*set_path(char *cmd)
{
	char	**all_paths;
	void	**tmp;
	char	*cmd_path;
	int		i;

	tmp = (void **)ft_split(ft_getenv("PATH"), ':');
	all_paths = (char **)arr_map(tmp, join_slash);
	arr_free(tmp);
	i = arr_size((void **)all_paths);
	while (--i)
	{
		cmd_path = ft_strjoin(all_paths[i], cmd);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		cmd_path = NULL;
	}
	arr_free((void **)all_paths);
	return (cmd_path);
}

void	set_redirections(t_list *tokens)
{
	t_tokenized	to_open[2];

	assign_files_to_open(tokens, to_open);
	if (open_file_redirect(&to_open[0]))
		error_handler(to_open[0].str, 1);
	if (open_file_redirect(&to_open[1]))
		error_handler(to_open[0].str, 1);
}
