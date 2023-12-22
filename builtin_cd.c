/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:09 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/22 15:37:16 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "env_util.h"
#include "error.h"
#include "libft/libft.h"
#include <stdio.h>

#define PATH_MAX 1024

int	chg_dir(char *path)
{
	char	*ret;
	char	pwd[PATH_MAX];
	char	*oldpwd;
	char	*ret_tmp;

	oldpwd = ft_strdup(getcwd(pwd, PATH_MAX));
	if (chdir(path) != 0)
		return (errorer("cd", path, "change directory failure", EXIT_FAILURE));
	ret = getcwd(pwd, PATH_MAX);
	if (!ret)
		return (errorer("cd", path,
				"getcwd : error retrieving current directory", EXIT_FAILURE));
		ret = ft_strdup(path);
	}
	else
		ret = ft_strdup(pwd);
	ret = ft_strjoin("PWD=", ret);
	oldpwd = ft_strjoin("OLDPWD=", oldpwd);
	env_remove("PWD");
	env_add(ret_tmp);
	env_remove("OLDPWD");
	env_add(oldpwd);
	free(ret);
	free(oldpwd);
	return (0);
}

int	ft_cd(char *arg)
{
	char	*path;

	if (!arg || arg[0] == ' '
		|| arg[0] == '\0' || ft_strncmp(arg, "--", 3) == 0)
	{
		path = (char *)ft_getenv("HOME");
		if (!path || *path == '\0' || *path == ' ')
			return (errorer("cd", 0, "HOME not set", EXIT_FAILURE));
		if (chg_dir(path) != 0)
			return (1);
		return (0);
	}
	if (ft_strncmp(arg, "-", 2) == 0)
	{
		path = (char *)ft_getenv("OLDPWD");
		if (!path)
			return (errorer("cd", 0, "OLDPWD not set", EXIT_FAILURE));
		if (chg_dir(path) != 0)
			return (1);
		return (0);
	}
	if (chg_dir(arg) != 0)
		return (1);
	return (0);
}

#include "builtin.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char *env[])
{
	(void)argv;
	(void)argc;
	env[0] = ft_strdup("VAR1=val1");
	env[1] = ft_strdup("VAR2=val1");
	env[2] = ft_strdup("HOME=/home/hohhoh");
	env[3] = ft_strdup("PWD=/home/hohhoh/Desktop/minishell");
	env[4] = ft_strdup("OLDPWD=");
	env[5] = ft_strdup("VAR3=val3");
	env[6] = ft_strdup("VAR4=val4");
	env[7] = ft_strdup("VAR5=val5");
	env[8] = ft_strdup("VAR6=val6");
	env[9] = ft_strdup("VAR7=val7");
	env[10] = 0;
	env_init(env);
	for (int i = 0; i < 10; ++i) free(env[i]);
	ft_env();
	printf("\n\n##############\n\n");
	ft_cd("..");
	ft_env();
	env_deinit();
	system("leaks ")
}