#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int	error_handler(char errmsg[], int opr)
{
	write(2, "minishell: ", 11);
	if (opr)
		perror(errmsg);
	else
	{
		write(2, errmsg, ft_strlen(errmsg));
		write(2, "\n", 1);
	}
	return (-1);
}
