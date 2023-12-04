#include "builtin.h"
#define PATH_MAX 1024

int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	ft_pwd(char **env, char **arg)
{
	char	*pwd[PATH_MAX];//char *[]?

	if (arg[1])
		return (errorer("pwd", 0, "too many arguments", EXIT_FAILURE));
	if (getcwd(pwd, PATH_MAX) != 0)
		printf("%s\n", pwd);
	else
		return (errorer("pwd", pwd, "access denied for current directory", EXIT_FAILURE));
	return (0);
}
