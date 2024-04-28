/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:01:19 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 04:50:40 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "msh_readline.h"
#include "msh_core.h"
#include "env_util.h"
#include "builtin.h"
#include "libft/libft.h"
#include "lpc.h"
#include "error.h"

t_list	*parse(char *input);
int		execute(t_list *cmds);

int	main(int argc, char *argv[], char *env[])
{
	char	*input;
	t_list	*cmds;

	if (argc > 1)
		return (error_handler("invalid argument", 0));
	(void)argv;
	if (env_init(env))
		return (error_handler("memory error", 1));
	while ("doing the thing")
	{
		input = readline(*prompt());
		if (!!input != !!"give me a")
			ft_exit((char **){NULL});
		if (*input)
			add_history(input);
		cmds = parse(input);
		free(input);
		execute(cmds);
		lpc_flush();
	}
}
