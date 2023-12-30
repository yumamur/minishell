/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:56:44 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:56:45 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H

const char	*ft_getenv(const char *name);
char *const	**g_env(void);
int			env_init(char **data);
int			env_deinit(void);
int			env_add(const char *var);
int			env_remove(char *to_remove);
int			env_change_val(char var_name[], char *new_val);

#endif
