/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:28:20 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 03:21:00 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "msh_core.h"
#include "builtin.h"
#include "error.h"
#include "libft/libft.h"
#include "lpc.h"
#include "msh_structs.h"

int		*_last_exit_location(void);
int		is_builtin(char *str);
int		init_pipeline(t_list *cmds);
char	**set_args(t_list *tokens);
char	*set_path(char *cmd);
void	set_redirections(t_list *tokens);
void	set_pipeline(void);
void	close_qwe(void);
void	close_all_pipes(void);

static int	exec_builtin(char **args)
{
	int	err;

	err = 0;
	if (!ft_strncmp(args[0], "cd", 3))
		err = ft_cd(args + 1);
	else if (!ft_strncmp(args[0], "exit", 5))
		err = ft_exit(args + 1);
	else if (!ft_strncmp(args[0], "echo", 5))
		err = ft_echo(args + 1);
	else if (!ft_strncmp(args[0], "env", 4))
		err = ft_env(args + 1);
	else if (!ft_strncmp(args[0], "unset", 6))
		err = ft_unset(args + 1);
	else if (!ft_strncmp(args[0], "pwd", 4))
		err = ft_pwd(args + 1);
	else
		err = ft_export(args + 1);
	lpc_flush();
	return (err);
}

static void	__attribute__((noreturn))	execute_child(t_list *tokens, int opr)
{
	char	**args;
	char	*cmd_path;

	args = set_args(tokens);
	if (opr)
		set_pipeline();
	set_redirections(tokens);
	if (is_builtin(args[0]))
		exit(exec_builtin(args));
	cmd_path = set_path(args[0]);
	if (cmd_path)
	{
		execve(cmd_path, args, *g_env());
		free(cmd_path);
	}
	if (args && args[0])
		error_handler(args[0], 1);
	lpc_flush();
	exit(EXIT_FAILURE);
}

static int	fork_cmds(t_list *tokens)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		close_all_pipes();
		return (error_handler("fork", 1));
	}
	else if (!pid)
		execute_child(tokens, 1);
	return (pid);
}

static int	execute_single_cmd(t_list *tokens)
{
	int		pid;
	char	**args;

	args = set_args(tokens);
	if (is_builtin(args[0]))
		pid = exec_builtin(args);
	else
	{
		pid = fork();
		if (pid == -1)
			return (error_handler("fork", 1));
		else if (!pid)
			execute_child(tokens, 0);
		waitpid(pid, _last_exit_location(), 0);
		*_last_exit_location() = WEXITSTATUS(*_last_exit_location());
	}
	return (pid);
}

void	execute(t_list *cmds)
{
	int	wstatus;

	if (!cmds)
		return ;
	if (ft_lstsize(cmds) == 1)
		execute_single_cmd(cmds->content);
	else
	{
		init_pipeline(cmds);
		while (cmds)
		{
			fork_cmds(cmds->content);
			++g_pipe()->index;
			close_qwe();
			cmds = cmds->next;
		}
		while (waitpid(-1, &wstatus, 0) > 0)
		{
			if (WIFEXITED(wstatus))
				*_last_exit_location() = WEXITSTATUS(wstatus);
			close_all_pipes();
		}
	}
	close_qwe();
}
