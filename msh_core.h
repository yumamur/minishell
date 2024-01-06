/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:33:30 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 03:10:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_CORE_H
# define MSH_CORE_H

# define PROMPT1 "\033[31m┌──(\033[m\033[32;1mminishell\033[m\033[31m)\033[m\n"
# define PROMPT2 "\033[31m└─>\033[m "

# include "msh_structs.h"

char *const			**g_env(void);
int					*_last_exit_location(void);
char				**prompt(void);
struct sigaction	*oldact(void);
t_pipehack			*g_pipe(void);
int					set_sighandler(void);
int					set_term_attr(void);

#endif
