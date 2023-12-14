/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:27 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:28:28 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "env_util.h"
#include "error.h"

int	ft_env(void)
{
	int		i;
	char	**env;

	i = 0;
	env = (char **)*g_env();
	if (!env)
		return (errorer("env", "dont have env.", NULL, EXIT_FAILURE));
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
