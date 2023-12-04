#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "msh_readline.h"
#include "msh_env.h"

#define CMD_PROMT "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m"

volatile sig_atomic_t	g_signum;

int		exec(char *cmd, char *envp[]);
char	**ft_str_wordtab(char *str);
void	sighandler_int(int sig);
int		set_sighandler(void);

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

int	main(void)
{
	char	*asd;
	int		ret;

	if (!isatty(0))
		return (-1);
	set_sighandler();
	while (1)
	{
		write(ttyslot(), CMD_PROMT, sizeof(CMD_PROMT));
		asd = readline("");
		if (!asd)
			exit(0);
		add_history(asd);
		execute_cmd(asd, &ret);
		printf("\n");
		free(asd);
	}
}
