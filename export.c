#include "builtin.h"
#include "msh_env.h"

void	**arr_realloc(void **arr, int to_add)
		__attribute__((alias("pt_util_realloc_ptr_arr")));
int	arr_size(void **arr)
	__attribute__((alias("pt_util_size_ptr_arr")));
int	errorer(char *command, char *detail, char *error_message, int error_nb);
void		***g_env(void);;
int ft_isalnum_str(char *str);

int	export_isvalid(char *arg)
{
	if (ft_isdigit(arg) && ft_isalnum_str(arg))
		return (1);
	return(0);
}

void	just_export(void)
{
	int	    i;
    char    **env;

	i = 0;
    env = g_env();
	if (!env)
		return(errorer("export", "dont have export.", NULL, EXIT_FAILURE));
	while(env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return(0);
}

void ft_export(char **arg)//env almmasina gerek yok, env_add(arg[1])
{
	int	i;
	char	**export;

	i = 0;
	export = g_env();
	if (!arg)
		just_export();
	if (arr_size(arg) > 1)
	{
		while (i <= arr_size(arg))
		{
			if (export_isvalid(arg[i]))
			{
				if (export_isenv(arg[i]))
					env_add(arg[i]);
				else
					arr_realloc(export, arg[i]);
			}
			i++;
		}
	}
	else
		return(errorer("export", "wrong argument count", NULL, EXIT_FAILURE));
	return (0);
}
