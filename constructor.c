/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:34:09 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:34:10 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "msh_prompt.h"

int		set_sighandler(void);

void __attribute__((constructor(101)))	constuctor(void)
{
	if (isatty(0))
		*prompt() = ft_strdup(PROMPT_DEFAULT);
	else if (!isatty(1))
		exit(0);
	else
		*prompt() = NULL;
	set_sighandler();
}
