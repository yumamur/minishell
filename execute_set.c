/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:30:05 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:30:06 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "env_util.h"
#include "error.h"
#include "msh_structs.h"
#include "msh_core.h"
#include "pt_util.h"
#include "libft/libft.h"
#include "lpc.h"

void	*join_slash(void *str);
int		count_args(t_list *tokens);
void	assign_files_to_open(t_list *lst, t_tokenized to_open[3]);
int		open_file_redirect(t_tokenized *tkn);
void	close_all_pipes();

int	init_pipeline(t_list *cmds)
{
	int	i;

	*g_pipe() = (t_pipehack){};
	g_pipe()->size = ft_lstsize(cmds) - 1;
	if (!g_pipe()->size)
		return (-1);
	g_pipe()->arr_pipe = ft_calloc(sizeof(t_pipe), g_pipe()->size);
	if (!g_pipe()->arr_pipe)
		return (error_handler("memory error", 1));
	lpc_export(g_pipe()->arr_pipe, NULL);
	i = -1;
	while (++i < g_pipe()->size)
	{
		if (pipe(g_pipe()->arr_pipe[i].fds))
			return (error_handler("pipe", 1));
	}
	return (0);
}

void	set_pipeline(void)
{
	int	i;

	i = g_pipe()->index;
	if (!i)
		dup2(g_pipe()->arr_pipe[i].fds[1], STDOUT_FILENO);
	else if (i == g_pipe()->size)
		dup2(g_pipe()->arr_pipe[i - 1].fds[0], STDIN_FILENO);
	else
	{
		dup2(g_pipe()->arr_pipe[i].fds[1], STDOUT_FILENO);
		dup2(g_pipe()->arr_pipe[i - 1].fds[0], STDIN_FILENO);
	}
	close_all_pipes();
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
		if (ptr->token == WORD)
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

	if (!access(cmd, F_OK))
		return (cmd);
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
		error_handler(to_open[1].str, 1);
}
