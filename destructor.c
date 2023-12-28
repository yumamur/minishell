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
#include "env_util.h"
#include "msh_prompt.h"

void __attribute__((destructor(101)))	destructor(void)
{
	env_deinit();
	free(*prompt());
}
