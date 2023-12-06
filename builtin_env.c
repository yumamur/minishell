#include "builtin.h"
#include <stdio.h>
#include "libft/libft.h"

void ***g_env(void);
int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	ft_env(void)
{
	int	    i;
    char    **env;

	i = 0;
    env = (char **)*g_env();
	if (!env)
		return(errorer("env", "dont have env.", NULL, EXIT_FAILURE));
	while(env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return(0);
}
