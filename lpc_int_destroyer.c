/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpc_int_destroyer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:18 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:57:19 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lpc_int.h"
#include <stdlib.h>

t_lpc_load	*lpc_int_find_destroyer(void *destroyer)
{
	t_lpc_storage	*ptr;
	t_uint			i;

	ptr = *lpc_int_storage();
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ptr->size)
	{
		if (ptr->load[i].destroyer == destroyer)
			return (&ptr->load[i]);
		else
			++i;
	}
	return (NULL);
}

int	lpc_int_new_destroyer(void *destroyer)
{
	t_lpc_storage	*ptr;

	ptr = *lpc_int_storage();
	if (!ptr)
		return (-1);
	if (ptr->size >= ptr->cap - 1)
		lpc_int_enlarge_storage();
	if (lpc_int_load_init(&ptr->load[ptr->size]))
		return (-1);
	ptr->load[ptr->size].destroyer = destroyer;
	++ptr->size;
	return (0);
}

void	lpc_int_destroy_p(t_lpc_load *load, int p)
{
	t_uint	i[2];

	if (!load)
		return ;
	i[0] = 0;
	while (i[0] < load->size && load->addr[i[0]].priority != p)
		++i[0];
	if (i[0] == load->size)
		return ;
	i[1] = 0;
	while (load->addr[i[0] + i[1]].priority == p && i[0] + i[1] < load->size)
		++i[1];
	while (i[1]--)
	{
		load->destroyer(load->addr[i[0] + i[1]].addr);
		load->addr[i[0] + i[1]] = (t_lpc_addr){};
		--load->size;
	}
}
