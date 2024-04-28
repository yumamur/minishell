/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:22:25 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 03:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "msh_readline.h"
#include "msh_core.h"
#include "msh_structs.h"

void	sanitize_strings(char **arr)
{
	int		i;
	char	*str;

	i = 0;
	while (arr[i])
	{
		str = arr[i];
		while (*str)
		{
			if (*str == '"')
			{
				ft_memmove(str, str + 1, ft_strlen(str) + 1);
				str = ft_strchr(str, '"');
				ft_memmove(str, str + 1, ft_strlen(str));
			}
			else if (*str == '\'')
			{
				ft_memmove(str, str + 1, ft_strlen(str) + 1);
				str = ft_strchr(str, '\'');
				ft_memmove(str, str + 1, ft_strlen(str));
			}
			++str;
		}
		++i;
	}
}

void	heredoc_loop(char *str, int fd)
{
	char	*rl;

	while (1)
	{
		rl = readline("> ");
		if (!rl)
			break ;
		else if (!ft_strncmp(rl, str, ft_strlen(str) + 1))
			break ;
		ft_putstr_fd(rl, fd);
		ft_putstr_fd("\n", fd);
	}
}

void	close_qwe(void)
{
	if (g_pipe()->fd != -1)
		close(g_pipe()->fd);
}

int	heredoc(t_tokenized *tkn)
{
	int	fds[2];

	pipe(fds);
	heredoc_loop(tkn->str, fds[1]);
	close(fds[1]);
	return (fds[0]);
}

void	close_all_pipes(void)
{
	int	i;

	i = -1;
	while (++i < g_pipe()->size)
	{
		close(g_pipe()->arr_pipe[i].fds[0]);
		close(g_pipe()->arr_pipe[i].fds[1]);
	}
}
