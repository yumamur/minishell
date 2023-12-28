/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:27 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 15:15:36 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env_util.h"
#include "error.h"

int	ft_env(char **arg)
{
	int		i;
	char	**env;

	if (arg)
		error_handler("invalid argument", 0);
	i = 0;
	env = (char **)*g_env();
	if (!env)
		return (error_handler("environment table is not set", 0));
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
