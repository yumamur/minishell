/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpc_int_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:03:36 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:03:37 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lpc_int.h"

void	lpc_int_add_addr(t_lpc_load *load, void *addr, int priority)
{
	t_uint	i;
	t_uchar	p;

	if (priority <= 0 || priority > 255)
		p = 255;
	else
		p = priority;
	i = 0;
	while (i <= load->size)
	{
		if (load->addr[i].priority > p)
			++i;
		else
		{
			memmove(load->addr + i + 1, load->addr + i,
				(load->size - i) * sizeof(t_lpc_addr));
			load->addr[i] = (t_lpc_addr){addr, p};
			++load->size;
			return ;
		}
	}
}
