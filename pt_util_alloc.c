/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_util_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:03:42 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:03:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

int		arr_size(void **arr);

void	arr_free(void **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void __attribute__((malloc))
	**arr_copy(void **arr)
{
	void	**ret;
	int		len;

	len = 0;
	while (arr[len])
		len++;
	ret = malloc((len + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	ret[len] = NULL;
	while (len--)
		ret[len] = arr[len];
	return (ret);
}

void __attribute__((malloc))
	**arr_realloc(void **arr, int to_add)
{
	void	**ret;
	int		len;

	len = arr_size(arr);
	ret = malloc((len + to_add + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	while (to_add)
	{
		ret[len + to_add] = NULL;
		--to_add;
	}
	while (len--)
		ret[len] = arr[len];
	free(arr);
	return (ret);
}

char __attribute__((malloc))
	**arr_deep_copy(const char **arr)
{
	char	**ret;
	int		i;

	if (!arr)
		return (NULL);
	ret = malloc((arr_size((void **)arr) + 1) * sizeof(*ret));
	if (!ret)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		ret[i] = ft_strdup(arr[i]);
		if (!ret[i])
		{
			arr_free((void **)ret);
			return (NULL);
		}
		++i;
	}
	ret[i] = 0;
	return (ret);
}
