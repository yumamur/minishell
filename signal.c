/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:03:10 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:03:11 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "msh_core.h"
#include "msh_readline.h"
#include "error.h"
#include "libft/libft.h"

volatile sig_atomic_t	g_signum;
void					display_prompt(int mode);

static void	sighandler(void)
{
	if (g_signum == SIGCONT)
	{
		write(ttyslot(), "\n", 1);
		rl_on_new_line();
		ft_putstr_fd(PROMPT1, ttyslot());
		rl_redisplay();
	}
	else if (g_signum == SIGINT)
	{
		rl_replace_line("", 1);
		write(ttyslot(), "\n", 1);
		rl_on_new_line();
		ft_putstr_fd(PROMPT1, ttyslot());
		rl_redisplay();
	}
	g_signum = 0;
}

void	signum_assign(int sig)
{
	g_signum = sig;
	sighandler();
}

void	unset_sighandler(void)
{
	if (sigaction(SIGINT, oldact(), NULL))
		error_handler("could not un-handle SIGINT:", 1);
	if (sigaction(SIGCONT, oldact(), NULL))
		error_handler("could not un-handle SIGCONT:", 1);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
}

void	donothing(int i)
{
	(void)i;
	return ;
}

int	set_sighandler(void)
{
	struct sigaction	sigint;

	sigint = (struct sigaction){};
	sigint.sa_handler = signum_assign;
	if (sigaddset(&sigint.sa_mask, SIGINT)
		|| sigaddset(&sigint.sa_mask, SIGCONT))
		return (-1);
	if (sigaction(SIGINT, &sigint, oldact()))
		error_handler("could not handle SIGINT:", 1);
	if (sigaction(SIGCONT, &sigint, oldact()))
		error_handler("could not handle SIGCONT:", 1);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	return (0);
}
