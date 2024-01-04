/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:08 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:29:09 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env_util.h"
#include "pt_util.h"
#include "error.h"

static int	is_valid(char *str)
{
	if (!(ft_isalpha(*str) || *str == '_'))
		return (0);
	while (*str)
	{
		if (ft_isalnum(*str) || *str == '_')
			++str;
		else
			return (0);
	}
	return (1);
}

int	ft_unset(char **arg)
{
	int	i;

	i = arr_size((void **)arg);
	if (!i || i == -1)
		return (error_handler("wrong argument count", 0));
	while (i--)
	{
		if (is_valid(arg[i]))
			env_remove(arg[i]);
	}
	return (0);
}
