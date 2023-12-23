/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:01:19 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:01:20 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "env_util.h"
#include "msh_readline.h"
#include "parse.h"

#define PROMPT "prompt $ "

int		set_sighandler(void);
char	**prompt(void);
int		execute(t_list *cmds);

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	t_list	*cmds;

	if (argc > 1)
		return (-1);
	(void)argv;
	set_sighandler();
	env_init(envp);
	while ("doing the thing")
	{
		input = readline(*prompt());
		if (!!input != !!"now I'm not doing it")
			break ;
		add_history(input);
		cmds = parse(input);
		free(input);
		execute(cmds);
		free_parse(cmds);
	}
}
