/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:00:46 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/05 00:40:41 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	arr_size(void **arr)
{
	int	i;

	if (!arr)
		return (-1);
	if (!*arr)
		return (0);
	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int	arr_index(void **arr, void *to_find)
{
	int	i;

	if (!arr)
		return (-1);
	else if (!to_find)
		return (arr_size(arr));
	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(arr[i], to_find, ft_strlen(to_find)))
			return (i);
		++i;
	}
	return (-1);
}

int	arr_discard_n(void **arr, int n)
{
	int	size;

	size = arr_size(arr);
	if (size == -1 || n < 0)
		return (-1);
	while (n < size)
	{
		arr[n] = arr[n + 1];
		++n;
	}
	arr[size - 1] = (void *)0;
	return (0);
}
