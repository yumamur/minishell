/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:58:03 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:58:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int	error_handler(char errmsg[], int opr)
{
	write(2, "minishell: ", 11);
	if (opr)
		perror(errmsg);
	else
	{
		write(2, errmsg, ft_strlen(errmsg));
		write(2, "\n", 1);
	}
	return (-1);
}
