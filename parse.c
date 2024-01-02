/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:04:13 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:04:14 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_structs.h"
#include "parse_util.h"
#include "libft/libft.h"
#include "error.h"
#include <stdio.h>

void	apply_extension(void *ptr)
{
	t_list		*head;
	t_tokenized	*tkn;

	head = ptr;
	while (head)
	{
		tkn = head->content;
		tkn->str = env_variable_extension(tkn->str);
		head = head->next;
	}
}

t_list	*parse(char *input)
{
	t_list				*cmds;
	t_tokenized_list	*lex;
	char				**tab;

	if (!*input)
		return (NULL);
	tab = ft_str_wordtab(input);
	if (!tab)
	{
		error_handler("syntax error. Probably caused by an un-terminated quote",
			0);
		return (NULL);
	}
	lex = lexer((const char **)tab);
	free(tab);
	if (!is_syntax_valid(lex))
	{
		error_handler("syntax is invalid", 0);
		return (NULL);
	}
	cmds = separate_by_pipe(lex);
	if (!is_cmds_valid(cmds))
		return (NULL);
	ft_lstiter(cmds, apply_extension);
	return (cmds);
}
