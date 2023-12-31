/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:29:46 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:47 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "msh_core.h"

extern void	unset_sighandler(void);
extern void	unset_term_attr(void);

void __attribute__((destructor(101)))	destructor(void)
{
	free(*prompt());
	// unset_term_attr();
	unset_sighandler();
}
