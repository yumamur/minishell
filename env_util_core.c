/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:04 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:57:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pt_util.h"

void	***g_env(void)
{
	static void	**env;

	return (&env);
}

int	env_deinit(void)
{
	int	i;

	i = arr_size(*g_env());
	if (i < 0)
		return (-1);
	while (i)
		free((*g_env())[--i]);
	free(*g_env());
	*g_env() = NULL;
	return (0);
}
