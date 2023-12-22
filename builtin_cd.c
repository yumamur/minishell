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

#define PATH_MAX 1024

int	change_env_var(char env_name[], const char *new_value)
{
	char	*buf;
	char	*var;

	buf = ft_strjoin(env_name, "=");
	if (!buf)
		return (-1);
	var = ft_strjoin(buf, new_value);
	if (!var)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	env_remove(env_name);
	env_add(var);
	free(var);
	return (0);
}

int	chg_dir(char *path)
{
	char	pwd[PATH_MAX];
	char	*new_pwd;
	char	*old_pwd;
	int		ctl;

	new_pwd = getcwd(pwd, PATH_MAX);
	if (!new_pwd || chdir(path) != 0)
	{
		error_handler("chdir error");
		return (-1);
	}
	old_pwd = ft_strdup(pwd);
	new_pwd = getcwd(pwd, PATH_MAX);
	if (!new_pwd)
	{
		free(old_pwd);
		error_handler("getcwd error");
		return (-1);
	}
	ctl = change_env_var("OLDPWD", old_pwd) + change_env_var("PWD", new_pwd);
	free(old_pwd);
	if (ctl)
		return (-1);
	return (0);
}

int	ft_cd(char *arg)
{
	char	*path;

	if (!arg || arg[0] == ' '
		|| arg[0] == '\0' || !ft_strncmp(arg, "--", 3))
	{
		path = (char *)ft_getenv("HOME");
		if (!path || *path == '\0' || *path == ' ')
			return (error_handler("HOME is not set"));
		if (chg_dir(path) != 0)
			return (1);
		return (0);
	}
	if (!ft_strncmp(arg, "-", 2))
	{
		path = (char *)ft_getenv("OLDPWD");
		if (!path)
			return (error_handler("OLDPWD is not set"));
		if (chg_dir(path) != 0)
			return (1);
		return (0);
	}
	if (chg_dir(arg) != 0)
		return (1);
	return (0);
}
