/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:29 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:57:30 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include "msh_structs.h"

static void	create_redir(void *tokenized)
{
	if (((t_tokenized *)tokenized)->token == FILE_OUT
		&& open(((t_tokenized *)tokenized)->str,
			O_CREAT | O_TRUNC | O_RDWR,
			0644))
		return ;
	else if (((t_tokenized *)tokenized)->token == FILE_APPEND
		&& open(((t_tokenized *)tokenized)->str,
			O_CREAT | O_APPEND | O_RDWR,
			0644))
		return ;
}

void	create_redirection_files(t_list *head)
{
	ft_lstiter(head, create_redir);
}
