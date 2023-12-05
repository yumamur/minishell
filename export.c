#include "builtin.h"

void	**arr_realloc(void **arr, int to_add);
int	arr_size(void **arr);
int	errorer(char *command, char *detail, char *error_message, int error_nb);
void ***g_env(void);
int ft_isalnum_str(char *str);
int	export_isenv(char *arg);
int	env_add(const char *var);

int	export_isvalid(char *arg)
{
	if (ft_isdigit(arg[0]) && ft_isalnum_str(arg))
		return (1);
	return(0);
}

int	just_export(void)
{
	int	    i;
    char    **env;

	i = 0;
    env = (char **)*g_env();
	if (!env)
		return(errorer("export", "dont have export.", NULL, EXIT_FAILURE));
	while(env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return(0);
}

int ft_export(char **arg)//env almmasina gerek yok, env_add(arg[1])
{
	int	i;

	i = 0;
	if (!arg)
		just_export();
	if (arr_size((void **)arg) > 1)
	{
		while (i <= arr_size((void **)arg))
		{
			if (export_isvalid(arg[i]))
					env_add(arg[i]);
			i++;
		}
	}
	else
		return(errorer("export", "wrong argument count", NULL, EXIT_FAILURE));
	return (0);
}
