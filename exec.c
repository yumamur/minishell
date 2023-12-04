#include <unistd.h>
#include <sys/wait.h>
#include "msh_env.h"

int		exec(char *cmd, char *envp[]);
int	execute_cmd(char *line, int *ret)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		exec(line, (char **)*g_env());
		return (-1);
	}
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		*ret = WEXITSTATUS(wstatus);
		return (0);
	}
	else if (WIFSIGNALED(wstatus))
	{
		*ret = WTERMSIG(wstatus);
		return (1);
	}
	return (-1);
}
