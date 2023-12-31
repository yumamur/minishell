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
#include "error.h"
#include "msh_readline.h"

volatile sig_atomic_t	g_signum;
struct sigaction		*oldact(void);

static void	sighandler(void)
{
	if (g_signum == SIGCONT || g_signum == SIGQUIT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (g_signum == SIGINT)
	{
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_signum = 0;
}

static void	signum_assign(int sig)
{
	g_signum = sig;
	sighandler();
}

void	unset_sighandler(void)
{
	if (sigaction(SIGINT, oldact(), NULL))
		error_handler("could not un-handle SIGINT:", 1);
	if (sigaction(SIGQUIT, oldact(), NULL))
		error_handler("could not un-handle SIGQUIT:", 1);
	if (sigaction(SIGTERM, oldact(), NULL))
		error_handler("could not un-handle SIGTERM:", 1);
	if (sigaction(SIGCONT, oldact(), NULL))
		error_handler("could not un-handle SIGCONT:", 1);
}

int	set_sighandler(void)
{
	struct sigaction	sigint;

	sigint = (struct sigaction){};
	sigint.sa_handler = signum_assign;
	if (sigaddset(&sigint.sa_mask, SIGINT)
		|| sigaddset(&sigint.sa_mask, SIGQUIT)
		|| sigaddset(&sigint.sa_mask, SIGTERM)
		|| sigaddset(&sigint.sa_mask, SIGCONT))
		return (-1);
	if (sigaction(SIGINT, &sigint, oldact()))
		error_handler("could not handle SIGINT:", 1);
	if (sigaction(SIGQUIT, &sigint, NULL))
		error_handler("could not handle SIGQUIT:", 1);
	if (sigaction(SIGTERM, &sigint, NULL))
		error_handler("could not handle SIGTERM:", 1);
	if (sigaction(SIGCONT, &sigint, NULL))
		error_handler("could not handle SIGCONT:", 1);
	return (0);
}
