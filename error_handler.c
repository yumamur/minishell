#include <unistd.h>
#include <stdio.h>

int	error_handler(char errmsg[])
{
	write(2, "minishell: ", 11);
	perror(errmsg);
	return (-1);
}
