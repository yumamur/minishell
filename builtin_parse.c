#include "builtin.h"
#include "msh_structs.h"

int	builtin_parser(t_cmd builtin)
{
	if (ft_strcmp(builtin.cmd, "cd") == 0 && ft_strlen(builtin.cmd) == 2)
		ft_cd(builtin.args);
	else if (ft_strcmp(builtin.cmd, "echo") == 0 && ft_strlen(builtin.cmd) == 4)
		ft_echo(builtin.args);
	else if (ft_strcmp(builtin.cmd, "unset") == 0 && ft_strlen(builtin.cmd) == 5)
		ft_unset(builtin.args);
	else if (ft_strcmp(builtin.cmd, "export") == 0 && ft_strlen(builtin.cmd) == 6)
		ft_export(builtin.args);
	else if (ft_strcmp(builtin.cmd, "pwd") == 0 && ft_strlen(builtin.cmd) == 3)
		ft_pwd(builtin.args);
	else if (ft_strcmp(builtin.cmd, "env") == 0 && ft_strlen(builtin.cmd) == 3)
		ft_env(builtin.args);
	else if (ft_strcmp(builtin.cmd, "exit") == 0 && ft_strlen(builtin.cmd) == 4)
		ft_exit(builtin.args);
	else
		return (1);
	return (0);
}
