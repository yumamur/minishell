/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpc_int_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:00:56 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:00:57 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LPC_INT_STRUCTS_H
# define LPC_INT_STRUCTS_H

# ifndef TYPEFT_H
#  include "typeft.h"
# endif

typedef void	(*t_ptr_destroyer)(void *);

typedef struct s_lpc_addr
{
	void	*addr;
	int		priority;
}	t_lpc_addr;

typedef struct s_lpc_load
{
	t_uint			cap;
	t_uint			size;
	t_lpc_addr		*addr;
	t_ptr_destroyer	destroyer;
}	t_lpc_load;

typedef struct s_lpc_storage
{
	t_ulong		threshhold;
	t_uint		cap;
	t_uint		size;
	t_lpc_load	*load;
}	t_lpc_storage;

#endif
