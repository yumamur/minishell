#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "builtin.h"
#include "env_util.h"
#include "error.h"
#include "libft/libft.h"
#include "lpc.h"

int		*_last_exit_location(void);
int		is_builtin(char *str);
char	**set_args(t_list *tokens);
char	*set_path(char *cmd);
void	set_redirections(t_list *tokens);

static void __attribute__((noreturn))	exec_builtin(char **args)
{
	int	err;

	err = 0;
	if (!ft_strncmp(args[0], "cd", 3))
		err = ft_cd(args + 1);
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
	if (err)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static void	__attribute__((noreturn))	execute_child(t_list *tokens)
{
	char	**args;
	char	*cmd_path;

	args = set_args(tokens);
	set_redirections(tokens);
	if (is_builtin(args[0]))
		exec_builtin(args);
	else
	{
		cmd_path = set_path(args[0]);
		if (cmd_path)
		{
			execve(cmd_path, args, *g_env());
			free(cmd_path);
		}
	}
	error_handler(args[0], 1);
	lpc_flush();
	exit(EXIT_FAILURE);
}

static int	fork_pipes(t_list *tokens)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (error_handler("fork", 1));
	else if (!pid)
		execute_child(tokens);
	return (pid);
}

void	execute(t_list	*cmds)
{
	int	pid;
	int	wstatus;

	if (!cmds)
		return ;
	while (cmds)
	{
		pid = fork_pipes(cmds->content);
		waitpid(pid, &wstatus, 0);
		*_last_exit_location() = WEXITSTATUS(wstatus);
		cmds = cmds->next;
	}
}
