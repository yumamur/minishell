/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:56:44 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/04 16:14:19 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H

# include "typeft.h"

const char	*ft_getenv(const char *name);
char		*ft_getenv2(t_c_char *name);
int			env_init(char **data);
int			env_deinit(void);
int			env_add(const char *var);
int			env_remove(char *to_remove);
int			env_change_val(char var_name[], char *new_val);

#endif
