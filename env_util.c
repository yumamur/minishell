/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:00:40 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:00:41 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "pt_util.h"
#include "error.h"

const char	*ft_getenv(const char *name);
void		***g_env(void);

int	env_init(void **data)
{
	static int	initialized;

	if (!data || !*data || initialized)
		return (-1);
	*g_env() = arr_deep_copy(data);
	if (!*g_env())
		return (-1);
	initialized = -1;
	return (0);
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

int	env_add(const char *var)
{
	char	**tmp;
	char	*var_dup;

	tmp = (char **)arr_realloc(*g_env(), 1);
	if (!tmp)
		return (-1);
	*g_env() = (void **)tmp;
	var_dup = ft_strdup(var);
	if (!var_dup)
		return (-1);
	(*g_env())[arr_size(*g_env())] = var_dup;
	return (0);
}

int	env_remove(char *to_remove)
{
	char	*var;

	var = (void *)ft_getenv(to_remove);
	if (!var)
		return (-1);
	var -= ft_strlen(to_remove) + 1;
	free(var);
	arr_discard_n(*g_env(), arr_index(*g_env(), var));
	return (0);
}

int	env_change_val(char var_name[], char *new_val)
{
	char	*var;
	int		i;

	var = (void *)ft_getenv(var_name);
	if (!var)
		return (-1);
	var -= ft_strlen(var_name) + 1;
	i = arr_index(*g_env(), var);
	free(var);
	var = ft_strjoin(var_name, "=");
	if (!var)
		return (error_handler("malloc error", 1));
	(*g_env())[i] = ft_strjoin(var, new_val);
	free(var);
	if (!(*g_env())[i])
		return (error_handler("malloc error", 1));
	return (0);
}
