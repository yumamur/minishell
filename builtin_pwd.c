#include <stdio.h>
#include <unistd.h>
#include "error.h"

#define PATH_MAX 1024

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) != 0)
		printf("%s\n", pwd);
	else
		return (errorer("pwd", pwd, "access denied for current directory", EXIT_FAILURE));
	return (0);
}
