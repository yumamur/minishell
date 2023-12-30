/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:44 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 18:35:13 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lpc.h"
#include "env_util.h"
#include "pt_util.h"
#include "error.h"

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
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (error_handler("not a valid identifier", 0));
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			return (error_handler("not a valid identifier", 0));
	}
	return (1);
}

void	just_export(void)
{
	int		i;
	char	**env;

	env = (char **)*g_env();
	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
}

int	ft_export(char **arg)
{
	int	i;

	i = 0;
	if (!*g_env())
		return (error_handler("environment table does not exist", 1));
	if (!*arg)
		just_export();
	else
	{
		while (i < arr_size((void **)arg))
		{
			if (export_isvalid(arg[i]) && !export_repeat_check(arg[i]))
				env_add(arg[i]);
			else
			{
				ft_putstr_fd("export: not a valid identifier", 2);
				ft_putstr_fd(arg[i], 2);
			}
			i++;
		}
	}
	return (0);
}
