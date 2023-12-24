/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:01:32 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:01:33 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_READLINE_H
# define MSH_READLINE_H

char	*readline(const char *prompt);
void	add_history(const char *string);
void	rl_clear_history(void);
void	rl_replace_line(const char *string, int i);
int		rl_on_new_line(void);
void	rl_redisplay(void);
#endif
