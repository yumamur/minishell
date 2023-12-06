#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pt_util.h"

int	ft_exit_atoi(char *arg, int last_cmd_exit)
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
			last_cmd_exit = 2;
		else
		 	(void)last_cmd_exit;
		i++;
	}
	return (num * neg);
}

void	exit_door(char *arg, int last_cmd_exit)
{
	long long	errnum;

	errnum = ft_exit_atoi(arg, last_cmd_exit);
	if (!(errnum < LLONG_MAX && errnum > LLONG_MIN))
	{
		free(arg);
		exit(-1);
	}
	last_cmd_exit = errnum % 256;
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
	if (!arg[0])
		exit(0);
	if (ft_atoi(arg[0]) < 0 || ft_atoi(arg[0]))
		exit();
	if (arg[1])
		return(errorer("exit", "too many argument for exit", NULL, EXIT_FAILURE));
}
