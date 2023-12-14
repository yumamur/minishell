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
#include "libft/libft.h"

#define PATH_MAX 1024

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) != 0)
		printf("%s\n", pwd);
	else
		return (errorer("pwd", pwd, "access denied for current directory",
				EXIT_FAILURE));
	return (0);
}
