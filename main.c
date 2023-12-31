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
#include "msh_readline.h"
#include "msh_core.h"
#include "builtin.h"
#include "env_util.h"
#include "lpc.h"
#include "parse.h"

#define PROMPT "\033[mprompt $ "
#define PROMPT1 "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m\n"
#define PROMPT2 "\033[31m└─>\033[m "

int		execute(t_list *cmds);

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	t_list	*cmds;

	if (argc > 1)
		return (-1);
	(void)argv;
	env_init(envp);
	while ("doing the thing")
	{
		input = readline(PROMPT1 PROMPT2);
		if (!!input != !!"give me a")
			ft_exit((char **){NULL});
		add_history(input);
		cmds = parse(input);
		free(input);
		execute(cmds);
		lpc_flush();
	}
}
