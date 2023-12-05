#include "builtin.h"
#define PATH_MAX 1024
#include <stdio.h>

int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) != 0)
		printf("%s\n", pwd);
	else
		return (errorer("pwd", pwd, "access denied for current directory", EXIT_FAILURE));
	return (0);
}
