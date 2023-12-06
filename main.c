#include <stdlib.h>
#include <unistd.h>
#include "env_util.h"
#include "msh_readline.h"
#include "libft/libft.h"
#include "msh_structs.h"

#define PROMPT "prompt $ "

int		set_sighandler(void);
int		execute(t_cmd *cmds);
t_cmd	*parse(char *input);

char	*prompt(int i)
{
	static char	*str;

	if (i)
	{
		if (!isatty(0))
			return (NULL);
		if (!str)
			str = ft_strdup(PROMPT);
		return (str);
	}
	if (*str)
		free(str);
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	if (argc > 1)
		return (-1);
	(void)argv;
	if (!isatty(0))
		return (-1);
	set_sighandler();
	env_init(envp);
	while (1)
	{
		input = readline(prompt(-1));
		if (!input)
			exit(0);
		add_history(input);
		execute(parse(input));
		free(input);
	}
	prompt(0);
}
