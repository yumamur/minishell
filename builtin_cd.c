/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:09 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/21 16:05:30 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "env_util.h"
#include "libft/libft.h"
#include "error.h"
#include "pt_util.h"

#define PATH_MAX 1024

int	chg_dir(char *path)
{
	char	pwd[PATH_MAX];
	char	*new_pwd;
	char	*old_pwd;

	old_pwd = getcwd(pwd, PATH_MAX);
	if (!old_pwd || chdir(path))
	{
		error_handler("cd", 1);
		return (-1);
	}
	old_pwd = ft_strdup(pwd);
	new_pwd = getcwd(pwd, PATH_MAX);
	if (!new_pwd)
	{
		free(old_pwd);
		error_handler("cd", 1);
		return (-1);
	}
	env_change_val("OLDPWD", old_pwd);
	env_change_val("PWD", pwd);
	free(old_pwd);
	return (0);
}

int	ft_cd(char **arg)
{
	char	*path;

	if (arr_size((void **)arg) > 1)
		return (error_handler("cd: too many arguments", 0));
	if (!*arg || !ft_strncmp(arg[0], "--", 3))
	{
		path = (char *)ft_getenv("HOME");
		if (!path)
			return (error_handler("HOME is not set", 0));
		if (chg_dir(path))
			return (-1);
		return (0);
	}
	if (!ft_strncmp(*arg, "-", 2))
	{
		path = (char *)ft_getenv("OLDPWD");
		if (!path)
			return (error_handler("OLDPWD is not set", 0));
		if (chg_dir(path))
			return (-1);
		return (0);
	}
	if (chg_dir(*arg))
		return (-1);
	return (0);
}
