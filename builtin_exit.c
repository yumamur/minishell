/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:29:13 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 18:25:56 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "error.h"
#include "pt_util.h"
#include "env_util.h"
#include "libft/libft.h"
#include "lpc.h"

extern int	*_last_exit_location(void);

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
			*_last_exit_location() = 2;
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
	*_last_exit_location() = errnum % 256;
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
			return (error_handler("exit argument must be numeric", 0));
		i++;
	}
	return (0);
}

int	ft_exit(char **arg)
{
	if (arr_size((void **)arg) > 1)
		return (error_handler("too many arguments, expected 1", 0));
	env_deinit();
	lpc_flush();
	if (!arg[0])
		exit(0);
	if (ft_atoi(arg[0]) < 0 || ft_atoi(arg[0]))
		exit(1);
	else
		exit(123212637);
}
