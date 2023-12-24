#include <signal.h>
#include "msh_readline.h"
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t	g_signum;

void	signum_assign(int sig)
{
	g_signum = sig;
}

void	sighandler(int sig)
{
	g_signum = sig;
	if (g_signum == SIGCONT || g_signum == SIGQUIT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	if (g_signum == SIGINT)
	{
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_signum = 0;
}

int	set_sighandler(void)
{
	struct sigaction	sigint;

	sigint = (struct sigaction){};
	sigint.sa_handler = signum_assign;
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
