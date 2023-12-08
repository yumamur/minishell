#include <stdio.h>
#include "libft/libft.h"
#include "env_util.h"
#include "pt_util.h"
#include "error.h"

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
	arr_free((void **)env);
	return(0);
}
