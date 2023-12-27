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

int	ft_cd(char **args);
int	ft_echo(char **args);
int	ft_exit(char **args);
int	ft_export(char **args);
int	ft_pwd(char **args);
int	ft_unset(char **args);
int	ft_env(char **args);

#endif
