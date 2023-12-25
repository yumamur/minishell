#include "env_util.h"
#include "msh_structs.h"
#include "pt_util.h"
#include "libft/libft.h"
#include "lpc.h"
#include <unistd.h>

static int	count_args(t_list *tokens)
{
	t_tokenized *ptr;
	int			count;

	count = 0;
	while (tokens)
	{
		ptr = tokens->content;
		if (ptr->token == CMD || ptr->token == WORD)
			++count;
		tokens = tokens->next;
	}
	return (count);
}

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
	char	*cmd_path;
	char	**all_paths;
	int		i;

	all_paths = ft_split(ft_getenv("PATH"), ':');
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
