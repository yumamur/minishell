#include "builtin.h"

void __attribute__((malloc))
	**pt_util_realloc_ptr_arr(void **arr, int to_add);
int	errorer(char *command, char *detail, char *error_message, int error_nb);
void		***g_env(void);;

int	env_borner(char **env, char *arg, int ex_flag)
{
	char *dec;

	dec = ft_strdup("declare -x ");
	if (!ft_isdigit(arg[0]))
	{
		if (ex_flag == 1)
		{
			dec = ft_strjoin(dec, arg);
			env = pt_util_realloc_ptr_arr(env, dec);
			free(dec);
		}
		else
			env = pt_util_realloc_ptr_arr(env, arg);
	}
	else
		return(errorer("export", arg, "invalid export argument", EXIT_FAILURE));
	return (0);
}

void ft_export(char **arg, char **env)
{
	int	i;
	char	**export;

	i = 0;
	export = env;
	if (arg_counter(arg) == 1 && ft_strcmp(arg[0], "export") == 0)
		ft_env(export);   //bakılacak
	if (arg_counter(arg) > 1)
	{
		while (i <= arg_counter(arg))
		{
			if (ft_strchr(arg, '=') == 0)
				env_borner(export, arg[i], 1);
			else
				env_borner(env, arg[i], 0);
			i++;
		}
	}
	else
		return(errorer("export", "wrong argument count", NULL, EXIT_FAILURE));
	return (0);
}