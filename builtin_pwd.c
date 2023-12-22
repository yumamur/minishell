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

int	ft_pwd(void)
{
	char	*ptr;
	char	pwd[PATH_MAX];

	ptr = getcwd(pwd, PATH_MAX);
	if (!ptr)
		printf("%s\n", pwd);
	else
		return (error_handler("pwd error"));
	return (0);
}
