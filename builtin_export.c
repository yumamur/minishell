/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:44 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 19:03:03 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lpc.h"
#include "env_util.h"
#include "error.h"
#include <stdio.h>

int	ft_env(char **args);

static int	is_var_existing(char *var)
{
	var = ft_strdup(var);
	lpc_export(var, NULL);
	*ft_strchr(var, '=') = 0;
	if (ft_getenv(var))
		return (1);
	return (0);
}

static int	is_valid(char *str)
{
	if (ft_isdigit(*str))
		return (0);
	while (*str && *str != '=')
	{
		if (ft_isalnum(*str) || *str == '_')
			++str;
		else
			return (0);
	}
	if (!*str)
		return (0);
	return (1);
}

static char	*val_trick(char *var)
{
	var = ft_strchr(var, '=');
	*var = 0;
	++var;
	return (var);
}

static int	validate_and_export(char **args)
{
	while (*args)
	{
		if (is_valid(*args))
		{
			if (is_var_existing(*args))
				env_change_val(*args, val_trick(*args));
			else
				env_add(*args);
		}
		else
		{
			ft_putstr_fd("export: not a valid identifier \'", 2);
			ft_putstr_fd(*args, 2);
			ft_putstr_fd("'\n", 2);
		}
		++args;
	}
	return (0);
}

int	ft_export(char **args)
{
	if (!*g_env())
		return (error_handler("environment table does not exist", 1));
	if (!*args)
		return (ft_env(args));
	else
		return (validate_and_export(args));
}
