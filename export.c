#include "builtin.h"
//#include "msh_env.c"

void __attribute__((malloc))
	**pt_util_realloc_ptr_arr(void **arr, int to_add);
int	errorer(char *command, char *detail, char *error_message, int error_nb);
void		***g_env(void);;

int	env_borner(char **env, char *arg, int ex_flag)
{
	char *dec;

//'set' builtin'imiz olmayacagi icin 'declare -x' ne ise yarar bilmiyorum
	dec = ft_strdup("declare -x ");
	if (!ft_isdigit(arg[0]))
	{
		if (ex_flag == 1)
		{
			dec = ft_strjoin(dec, arg);//leak
			env = pt_util_realloc_ptr_arr(env, dec);//arr_realloc
			free(dec);
		}
		else
			env = pt_util_realloc_ptr_arr(env, arg);
	}
	else
		return(errorer("export", arg, "invalid export argument", EXIT_FAILURE));
	return (0);
}

//env variable sadece alfabetik karakterle baslayabilir
//Devaminda sadece alphanumeric karakter alabilir

void ft_export(char **arg, char **env)//env almmasina gerek yok, env_add(arg[1])
{
	int	i;
	char	**export;

	i = 0;
	export = env;
	if (arg_counter(arg) == 1 && ft_strcmp(arg[0], "export") == 0)//bu yok, hem export hem exec icin `;` veya `\` gerekiyor
		ft_env(export);   //bakılacak
	if (arg_counter(arg) > 1)

	{
		while (i <= arg_counter(arg))//arr_size
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
