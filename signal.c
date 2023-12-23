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

#include <signal.h>
#include "msh_readline.h"
#include <stdio.h>
#include <unistd.h>

#define CMD_PROMT "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m"

extern volatile sig_atomic_t	g_signum;

void	sighandler(int sig)
{
	g_signum = sig;
	if (g_signum == SIGCONT || g_signum == SIGQUIT)
	{
		rl_on_new_line();
		write(ttyslot(), CMD_PROMT, sizeof(CMD_PROMT));
		rl_redisplay();
	}
	if (g_signum == SIGINT)
	{
		rl_replace_line("", 1);
		write(ttyslot(), "\n"CMD_PROMT, sizeof(CMD_PROMT) + 1);
		rl_on_new_line();
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
