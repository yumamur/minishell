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
#include "lpc.h"
#include "error.h"

int		is_syntax_valid(t_tokenzied_list *lst);
t_list	*separate_by_pipe(t_tokenzied_list *tkn_list);
void	create_redirection_files(void *inner_list);
void	validate_cmds(void *inner_list);
int		is_cmds_valid(t_list *head);

void	free_parse(t_list *parsed)
{
	t_list	*ptr;

	ptr = parsed;
	while (ptr)
	{
		lpc_export(ptr, NULL);
		ptr = ptr->next;
	}
	lpc_flush();
}

#include <stdio.h>
void	print_lex(t_tokenzied_list *lex)
{
	int i = 0;
	while (lex)
	{
		printf("%d   %d %s\n", ++i, lex->token, lex->str);
		lex = lex->next;
	}
}

t_list	*parse(char *input)
{
	t_list				*cmds;
	t_tokenzied_list	*lex;
	char				**tab;

	if (!*input)
		return (NULL);
	tab = ft_str_wordtab(input);
	lex = lexer((const char **)tab);
	free(tab);
	print_lex(lex);
	if (!is_syntax_valid(lex))
	{
		error_handler(" here syntax is invalid", 0);
		return (NULL);
	}
	cmds = separate_by_pipe(lex);
	ft_lstiter(cmds, validate_cmds);
	ft_lstiter(cmds, create_redirection_files);
	if (!is_cmds_valid(cmds))
	{
		free_parse(cmds);
		return (NULL);
	}
	return (cmds);
}
