/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:34:09 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/04 16:16:59 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "msh_core.h"
#include "env_util.h"
#include "error.h"
#include "libft/libft.h"

#if __MACH__ || __APPLE__

# include <crt_externs.h>

void __attribute__((constructor(101)))	constuctor(void)
{
	env_init(*_NSGetEnviron());
	if (isatty(0))
		*prompt() = ft_strjoin("\033[m", PROMPT1 PROMPT2);
	else if (!isatty(1))
		exit(error_handler("We need a tty in order to operate", 0));
	else
		*prompt() = NULL;
	if (set_sighandler())
		exit(error_handler("error setting signal handler, exiting", 1));
	if (set_term_attr())
		exit(error_handler("error setting terminal attributes, exiting", 1));
}

#elif unix || __unix || __unix__

void __attribute__((constructor(101)))	constuctor(void)
{
	env_init(__environ);
	if (isatty(0))
		*prompt() = ft_strjoin("\033[m", PROMPT1 PROMPT2);
	else if (!isatty(1))
		exit(error_handler("We need a tty in order to operate", 0));
	else
		*prompt() = NULL;
	if (set_sighandler())
		exit(error_handler("error setting signal handler, exiting", 1));
	if (set_term_attr())
		exit(error_handler("error setting terminal attributes, exiting", 1));
}

#endif