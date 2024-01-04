/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:44 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/05 00:36:50 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_core.h"
#include "env_util.h"
#include "error.h"
#include "libft/libft.h"
#include <stdio.h>

int		just_export(void);
int		export_is_repeat(char *var);
char	*ft_getenv2(t_c_char *name);
int		env_change_val(char var_name[], char *new_val);

static int	is_var_existing(char *var)
{
	char	*ptr;

	var = ft_strdup(var);
	ptr = ft_strchr(var, '=');
	if (ptr)
		*ptr = 0;
	if (ft_getenv2(var))// || export_is_repeat(var) == 1)
	{
		free(var);
		return (1);
	}
	free(var);
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
	return (1);
}

static char	*val_trick(char *var)
{
	// if (ft_strchr(var, '='))
	// 	var = ft_strchr(var, '=');
	if (!var)
		return (0);
	var = ft_strchr(var, '=');
	if (!var)
		return (NULL);
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
		return (just_export());
	else
		return (validate_and_export(args));
}
