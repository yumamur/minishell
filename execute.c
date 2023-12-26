#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "env_util.h"
#include "error.h"
#include "libft/libft.h"
#include "lpc.h"

int		*_last_exit_location(void);
char	**set_args(t_list *tokens);
char	*set_path(char *cmd);

#include <stdio.h>
static void	__attribute__((noreturn))	execute_child(t_list *tokens)
{
	char	**args;
	char	*cmd_path;

	args = set_args(tokens);
	cmd_path = set_path(args[0]);
	printf("%s\n", cmd_path);
	if (!cmd_path)
		exit(1);
	execve(cmd_path, args, *g_env());
	if (cmd_path)
		free(cmd_path);
	lpc_flush();
	exit(error_handler(args[0], 1));
}

int	fork_pipes(t_list *tokens)
{
	int	fds[2];
	int	pid;

	if (pipe(fds))
		return (error_handler("pipe", 1));
	pid = fork();
	if (pid == -1)
		return (error_handler("fork", 1));
	else if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		execute_child(tokens);
	}
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
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
	dup2()
}
