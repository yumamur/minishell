#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "msh_readline.h"

#define CMD_PROMT "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m"
#define CMD_PROMT2 "\033[38;2;200;60;120m└─>\033[m "

volatile sig_atomic_t	g_signum;

int		exec(char *cmd, char *envp[]);
char	**ft_str_wordtab(char *str);
void	sighandler_int(int sig);
int		set_sighandler(void);

// struct s_prompt
// {
// 	char	buf[100];
// };

// struct s_prompt	msh_prompt(void)
// {
// 	struct s_prompt	ret;

// 	ft_memcpy(ret.buf, get_colour());
// 	ft_memcpy(ret.buf, "minishell", 10);
// 	return (ret);
// }

int	execute_cmd(char *line, int *ret)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		exec(line, __environ);
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

	set_sighandler();
	while (1)
	{
		// asd = readline(msh_prompt(env).buf);
		asd = readline(CMD_PROMT"\n"CMD_PROMT2);
		if (!asd)
			exit(0);
		if (*asd)
		{
			add_history(asd);
			execute_cmd(asd, &ret);
		}
		printf("\n");
		free(asd);
	}
}
