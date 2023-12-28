/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:28:07 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:28:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "msh_structs.h"

int	set_next_token(t_tokenized_list *node, t_token to_set)
{
	if (node->token == WORD)
		return (node->token = to_set);
	else
		return (node->token = INVALID);
}

int	is_syntax_valid(t_tokenized_list *lst)
{
	t_tokenized_list	*ptr;
	int					err;

	if (lst->token == PIPE || lst->token == OR || lst->token == AND)
		return (lst->token = INVALID);
	err = 0;
	ptr = lst->next;
	while (ptr)
	{
		if (lst->token != WORD && lst->token == ptr->token)
			return (lst->token = INVALID);
		else if (lst->token == REDIRECT_IN)
			err = set_next_token(ptr, FILE_IN);
		else if (lst->token == REDIRECT_OUT)
			err = set_next_token(ptr, FILE_OUT);
		else if (lst->token == APPEND)
			err = set_next_token(ptr, FILE_APPEND);
		else if (lst->token == HEREDOC)
			err = set_next_token(ptr, EOF_HEREDOC);
		if (err)
			return (!(lst->token = INVALID));
		lst = ptr;
		ptr = ptr->next;
	}
	return (1);
}

int	is_cmds_valid(t_list *head)
{
	t_tokenized	*ptr;
	t_list		*inner_list;

	while (head)
	{
		inner_list = head->content;
		while (inner_list)
		{
			ptr = inner_list->content;
			if (ptr->token == INVALID)
				return (0);
			inner_list = inner_list->next;
		}
		head = head->next;
	}
	return (1);
}
