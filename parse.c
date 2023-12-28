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
#include "lexer.h"
#include "libft/libft.h"
#include "error.h"
#include <stdio.h>

int		is_syntax_valid(t_tokenized_list *lst);
t_list	*separate_by_pipe(t_tokenized_list *tkn_list);
void	create_redirection_files(void *inner_list);
void	validate_cmds(void *inner_list);
int		is_cmds_valid(t_list *head);

t_list	*parse(char *input)
{
	t_list				*cmds;
	t_tokenized_list	*lex;
	char				**tab;

	if (!*input)
		return (NULL);
	tab = ft_str_wordtab(input);
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
	return (cmds);
}
