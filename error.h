/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:23 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:29:24 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ERROR_H
# define ERROR_H

# define MSH_ECD "cd: "
# define MSH_EPWD "pwd: "

int /*__attribute__((deprecated("this is deprecated", "error_handler()")))*/
	errorer(char *command, char *detail, char *error_message, int error_nb);

void	error_handler(char errmsg[]);

#endif
