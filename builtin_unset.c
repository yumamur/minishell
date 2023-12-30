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

#include "env_util.h"
#include "pt_util.h"
#include "error.h"
#include <stdio.h>

int	export_isvalid(char *str);

int	ft_unset(char **arg)
{
	int	i;

	i = arr_size((void **)arg);
	if (!i || i == -1)
		return (error_handler("wrong argument count", 0));
	while (i--)
	{
		if (export_isvalid(arg[i]))
		{
			printf("%s\n", arg[i]);
			if (env_remove(arg[i]) == -1)
				return (error_handler("not a valid identifier", 0));
		}
	}
	return (0);
}
