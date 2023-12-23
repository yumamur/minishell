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
