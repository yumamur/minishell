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

int	export_isvalid(char *str);

int	ft_unset(char **arg)
{
	int	i;

	i = 0;
	if (arr_size((void **)arg) >= 1)
	{
		while (i < arr_size((void **)arg))
		{
			if (export_isvalid(arg[i]))
				if (env_remove(arg[i]) == -1)
					return (error_handler("not a valid identifier"));
			i++;
		}
	}
	else
		return (error_handler("wrong argument count"));
	return (0);
}
