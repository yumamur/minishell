#include "builtin.h"
#include <limits.h>

int	ret_for_exit = 0; //msh_struct tan düzenlenecek
void	ft_free_2pt(char **arr);
int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	ft_exit_atoi(char *arg)
{
	int			i;
	long		neg;
	long long	num;

	i = 0;
	neg = 1;
	num = 0;
	if ((arg[i] && (arg[i] == '-')) || (arg[i] == '+'))
		if (arg[i++] == '-')
			neg *= -1;
	while (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\t' || arg[i] == '\v'
		|| arg[i] == '\f' || arg[i] == '\r')
		i++;
	while (arg[i] >= 48 && arg[i] <= 57)
	{
		num = num * 10 + (arg[i] - 48);
		if (((i == 18 && neg == 1) && (arg[i] > '7' && arg[i] <= '9'))
			|| ((i == 19 && neg == -1) && (arg[i] == '9')))
			ret_for_exit = 2;
		i++;
	}
	return (num * neg);
}

void	exit_door(char *arg)
{
	long long	errnum;

	errnum = ft_exit_atoi(arg);
	if (!(errnum < LLONG_MAX && errnum > LLONG_MIN))
	{
		free(arg);
		exit(-1);
	}
	ret_for_exit = errnum % 256;
}

int	numeric_ctrl(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (errorer("exit", arg, "exit arguments must be numeric", EXIT_FAILURE));
		i++;
	}
	return (0);
}

int	ft_exit(char **arg)
{
	if (!arg[1])
	{
		ft_free_2pt(arg);
		exit(0);
	}
	if (numeric_ctrl(arg[1]) == 1)
	{
		ft_free_2pt(arg);
		exit(-1);
	}
	if (arg[2])
		return(errorer("exit", "too many argument for exit", NULL, EXIT_FAILURE));
	else
		exit_door(arg[1]);
	exit(ret_for_exit);
}