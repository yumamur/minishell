/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:21 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:28:22 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	arg_counter(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

int	ft_echo(char **arg)
{
	int	n_flag;
	int	arg_size;
	int	i;

	n_flag = 0;
	i = 0;
	arg_size = arg_counter(arg);
	if (arg_size > 1)
	{
		if (ft_strcmp(arg[0], "-n") == 0)
		{
			n_flag = 1;
			i = 1;
		}
		while (arg[i])
		{
			ft_putstr_fd(arg[i], STDOUT_FILENO);
			if (arg[i + 1] && arg[i][0] != '\0')
				write (1, " ", 1);
			i++;
		}
	}
	if (n_flag == 0)
		write (1, "\n", 1);
	return (0);
}
