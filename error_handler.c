#include <unistd.h>
#include <stdio.h>

void	error_handler(char errmsg[])
{
	write(2, "minishell: ", 11);
	perror(errmsg);
}
