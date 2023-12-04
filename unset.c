#include "builtin.h"

int	env_remove(char *to_remove);
int	export_isvalid(char *arg);
int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	ft_unset(char **arg)
{
	int	i;

	i = 0;
	if (arg_counter(arg) > 1)
	{
		while (i <= arg_counter(arg))
		{
			if (export_isvalid(arg[i]))
				if(env_remove(arg[i]) == -1);
					return(errorer("unset", "env", "cant found", EXIT_FAILURE));
			i++;
		}
	}
	else
		return (errorer("unset", "wrong argument count", NULL, NULL));
	return(0);
}
