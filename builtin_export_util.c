/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:47:42 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 03:07:31 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "msh_core.h"
#include "error.h"

int	export_is_repeat(char *var)
{
	char	**env;
	int		i;

	i = 0;
	env = (char **)*g_env();
	while (env[i])
	{
		if (ft_strcmp(env[i], var) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	just_export(void)
{
	int		i;
	char	**env;

	env = (char **)*g_env();
	if (!env)
		return (error_handler("environment table is not set", 0));
	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
