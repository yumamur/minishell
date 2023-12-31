/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpc_int_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:12 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:57:13 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lpc_int.h"
#include "lpc_int_structs.h"
#include "typeft.h"
#include <stdlib.h>

static void	nullify_load_addresses(t_lpc_addr *arr, int cap)
{
	while (cap--)
		arr[cap] = (t_lpc_addr){};
}

int	lpc_int_load_init(t_lpc_load *load)
{
	if (!load)
		return (-1);
	*load = (t_lpc_load){};
	load->addr = malloc(4 * sizeof(t_lpc_addr));
	if (!load->addr)
		return (-1);
	load->cap = 4;
	load->size = 0;
	nullify_load_addresses(load->addr, load->cap);
	return (0);
}

int	lpc_int_enlarge_load(t_lpc_load *load)
{
	t_lpc_addr	*tmp;
	t_uint		i;

	if (!load)
		return (-1);
	tmp = malloc(load->cap * 2 * sizeof(t_lpc_addr));
	if (!tmp)
		return (-1);
	load->cap *= 2;
	nullify_load_addresses(tmp, load->cap);
	i = 0;
	while (i < load->size)
	{
		tmp[i] = load->addr[i];
		++i;
	}
	free(load->addr);
	load->addr = tmp;
	return (0);
}

int	lpc_int_load(void *addr, void *destroyer, int priority)
{
	t_lpc_storage	*ptr;
	t_lpc_load		*ld_ptr;

	ptr = *lpc_int_storage();
	if (!ptr || !addr)
		return (-1);
	if (!destroyer)
		destroyer = free;
	ld_ptr = lpc_int_find_destroyer(destroyer);
	if (!ld_ptr)
	{
		if (lpc_int_new_destroyer(destroyer))
			return (-1);
		return (lpc_int_load(addr, destroyer, priority));
	}
	if (ld_ptr->size >= ld_ptr->cap - 1
		&& lpc_int_enlarge_load(ld_ptr))
		return (-1);
	lpc_int_add_addr(ld_ptr, addr, priority);
	return (0);
}
