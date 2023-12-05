#include "builtin.h"
#include "msh_structs.h"

int	last_cmd_exit = 0;

int	builtin_parser(t_cmd builtin)
{
	// if (ft_strcmp(builtin.cmd, "cd") == 0 && ft_strlen(builtin.cmd) == 2)
	// 	ft_cd((char *)builtin.args[0]);
	if (ft_strcmp(builtin.cmd, "echo") == 0 && ft_strlen(builtin.cmd) == 4)
	 	ft_echo((char **)builtin.args);
	// else if (ft_strcmp(builtin.cmd, "unset") == 0 && ft_strlen(builtin.cmd) == 5)
	// 	ft_unset((char **)builtin.args);
	// else if (ft_strcmp(builtin.cmd, "export") == 0 && ft_strlen(builtin.cmd) == 6)
	// 	ft_export((char **)builtin.args);
	// else if (ft_strcmp(builtin.cmd, "pwd") == 0 && ft_strlen(builtin.cmd) == 3)
	// 	ft_pwd();
	// else if (ft_strcmp(builtin.cmd, "env") == 0 && ft_strlen(builtin.cmd) == 3)
	// 	ft_env();
	// else if (ft_strcmp(builtin.cmd, "exit") == 0 && ft_strlen(builtin.cmd) == 4)
	// 	ft_exit((char **)builtin.args, last_cmd_exit);
	else
		return (1);
	return (0);
}
