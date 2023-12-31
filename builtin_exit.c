/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:29:13 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 18:25:56 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "error.h"
#include "pt_util.h"
#include "env_util.h"
#include "lpc.h"

int	random_status(void)
{
	unsigned int	buf;
	int				fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, &buf, 4) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (buf);
}

int	ft_exit(char **arg)
{
	int	status;

	if (arr_size((void **)arg) > 1)
		return (error_handler("too many arguments, expected 1", 0));
	env_deinit();
	lpc_flush();
	write(2, "See you soon\n", 13);
	if (!*arg)
		exit(0);
	status = ft_atoi(arg[0]);
	if (status)
		exit(status);
	else
		exit(random_status());
}
