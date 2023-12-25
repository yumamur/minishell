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

#include "libft/libft.h"
#include "pt_util.h"

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
	(*g_env())[arr_size(*g_env()) - 1] = var_dup;
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
