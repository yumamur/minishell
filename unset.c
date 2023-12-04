#include "builtin.h"

int	env_remove(char *to_remove);

// int	env_killer(char **env, char *arg)
// {
// 	int	i;
// 	int freer;
// 	int	f_flag;
// 	char	**export; //struct yapılınca gelecek

// 	i = 0;
// 	freer = 0;
// 	f_flag = 0;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], arg, ft_strlen(arg)) == 0)
// 		{
// 			f_flag = 1;
// 			while (env[i][freer])
// 			{
// 				env[i][freer] = 0;
// 				freer++;
// 			}
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	freer = 0;
// 	while (export[i])
// 	{
// 		if (ft_strncmp(export[i], arg, ft_strlen(arg)) == 0)
// 		{
// 			f_flag = 1;
// 			while (export[i][freer])
// 			{
// 				export[i][freer] = 0;
// 				freer++;
// 			}
// 		}
// 		i++;
// 	}
// 	if (f_flag == 0)
// 		return(errorer("unset", "env cant found", stderr(errno), errno));
// 	return(0);

// }

//env variable name parameter validation (export ile ayni)

int	ft_unset(char **env, char **arg)//env unused
{
	int	i;

	i = 0;
	if (arg_counter(arg) > 1)
	{
		while (i <= arg_counter(arg))
		{
			env_remove(arg[i]);
			i++;
		}
	}
	else
		return (errorer("unset", "wrong argument count", NULL, NULL));
	return(0);
}
