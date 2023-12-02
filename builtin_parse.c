#include "libft/libft.h"

int builtin_parser(char *env)
{
	if (ft_strcmp(env, "cd") == 0 && ft_strlen(env) == 2)
		ft_cd(env);
	else if (ft_strcmp(env, "echo") == 0 && ft_strlen(env) == 4)
		ft_echo(env);
	else if (ft_strcmp(env, "unset") == 0 && ft_strlen(env) == 5)
		ft_unset(env);
	else if (ft_strcmp(env, "export") == 0 && ft_strlen(env) == 6)
		ft_export(env);
	else if (ft_strcmp(env, "pwd") == 0 && ft_strlen(env) == 3)
		ft_pwd(env);
	else if (ft_strcmp(env, "env") == 0 && ft_strlen(env) == 3)
		ft_env(env);
	else if (ft_strcmp(env, "exit") == 0 && ft_strlen(env) == 4)
		ft_exit(env);
	else
		return (1);
	return (0);
}
