/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:11 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:29:12 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_cd(char *arg);
int	ft_echo(char **arg);
int	ft_exit(char **arg, int last_cmd_exit);
int	ft_export(char **arg);
int	ft_pwd(void);
int	ft_unset(char **arg);
int	ft_env(void);

#endif
