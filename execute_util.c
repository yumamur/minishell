/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:30:11 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:30:12 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "msh_structs.h"
#include "libft/libft.h"

int	is_builtin(const char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "pwd", 4)
		|| !ft_strncmp(cmd, "unset", 6)
		|| !ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

void	assign_files_to_open(t_list *lst, t_tokenized to_open[2])
{
	t_tokenized	*ptr;

	to_open[0] = (t_tokenized){};
	to_open[1] = (t_tokenized){};
	while (lst)
	{
		ptr = lst->content;
		if (ptr->token == FILE_IN || ptr->token == EOF_HEREDOC)
			to_open[0] = *ptr;
		else if (ptr->token == FILE_OUT || ptr->token == APPEND)
			to_open[1] = *ptr;
		lst = lst->next;
	}
}

int	open_file_redirect(t_tokenized *tkn)
{
	int	fd;

	if (!tkn->str)
		return (0);
	fd = -1;
	if (tkn->token == FILE_IN)
		fd = open(tkn->str, O_RDONLY);
	else if (tkn->token == FILE_OUT)
		fd = open(tkn->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (tkn->token == FILE_APPEND)
		fd = open(tkn->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == -1)
		return (-1);
	if ((tkn->token == FILE_IN || tkn->token == FILE_APPEND)
		&& dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	else if (tkn->token == FILE_OUT && dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	count_args(t_list *tokens)
{
	t_tokenized	*ptr;
	int			count;

	count = 0;
	while (tokens)
	{
		ptr = tokens->content;
		if (ptr->token == WORD)
			++count;
		tokens = tokens->next;
	}
	return (count);
}

void	*join_slash(void *str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = ft_strjoin(str, "/");
	return (ret);
}
