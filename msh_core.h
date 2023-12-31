/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:33:30 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:33:31 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_CORE_H
# define MSH_CORE_H

# define PROMPT_DEFAULT "minishell @ "
# define PROMPT_V2
# define PROMPT_V3

char *const			**g_env(void);
int					*_last_exit_location(void);
char				**prompt(void);
struct sigaction	*oldact(void);

#endif
