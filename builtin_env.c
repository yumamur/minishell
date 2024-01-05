/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:27 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/05 02:01:04 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "msh_core.h"
#include "error.h"

int	ft_env(char **arg)
{
	int		i;
	char	**env;
	char	*equal_pos;

	if (*arg)
		return (error_handler("invalid argument", 0));
	i = 0;
	env = (char **)*g_env();
	if (!env)
		return (error_handler("environment table is not set", 0));
	while (env[i])
	{
		equal_pos = ft_strchr(env[i], '=');
		if (equal_pos && *(equal_pos + 1) != '\0')
			ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
