/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:03 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:29:04 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "error.h"

#define PATH_MAX 1024

int	ft_pwd(char **arg)
{
	char	*ptr;
	char	pwd[PATH_MAX];

	if (*arg)
		return (error_handler("wrong number of arguments", 0));
	ptr = getcwd(pwd, PATH_MAX);
	if (ptr)
		printf("%s\n", pwd);
	else
		return (error_handler("pwd error", 1));
	return (0);
}
