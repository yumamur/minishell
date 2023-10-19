#include "minishell.h"

#define CMD_PROMT "\033[38;2;200;60;120m┌──(\033[m\033[32;1mminishell\033[m\033[38;2;200;60;120m)"
#define CMD_PROMT2 "└─>\033[m"
volatile sig_atomic_t	g_signum;

void	sighandler_int(int sig)
{
	g_signum = sig;
	if (g_signum == SIGCONT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (g_signum == SIGINT || g_signum == SIGQUIT)
	{
		printf("\n\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		printf(CMD_PROMT"\n");
		rl_redisplay();
		g_signum = 0;
	}
}

int	set_sighandler(void)
{
	struct sigaction sigint;

	sigint = (struct sigaction){};
	sigint.sa_handler = sighandler_int;
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
int	main(void)
{
	char *asd;

	set_sighandler();
	while (1)
	{
		// asd = readline(msh_prompt().buf);
		asd = readline(CMD_PROMT"\n"CMD_PROMT2);
		if (!asd)
			break ;
		if (*asd)
			add_history(asd);
		free(asd);
	}
}
