#include "minishell.h"

#define CMD_PROMT "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m"

extern int	g_signum;

void	sighandler(int sig)
{
	g_signum = sig;
	if (g_signum == SIGCONT)
	{
		rl_on_new_line();
		printf(CMD_PROMT"\n");
		rl_redisplay();
	}
	if (g_signum == SIGINT || g_signum == SIGQUIT)
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		printf("\n\n");
		printf(CMD_PROMT"\n");
		rl_redisplay();
	}
	g_signum = 0;
}

int	set_sighandler(void)
{
	struct sigaction	sigint;

	sigint = (struct sigaction){};
	sigint.sa_handler = sighandler;
	if (sigaddset(&sigint.sa_mask, SIGINT)
		|| sigaddset(&sigint.sa_mask, SIGQUIT)
		|| sigaddset(&sigint.sa_mask, SIGCONT))
		return (-1);
	if (sigaction(SIGINT, &sigint, NULL)
		|| sigaction(SIGQUIT, &sigint, NULL)
		|| sigaction(SIGCONT, &sigint, NULL))
		return (-1);
	return (0);
}
