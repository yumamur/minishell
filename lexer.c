/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:37:43 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:03 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "lpc.h"
#include "lexer.h"
#include "msh_structs.h"
#include "typeft.h"

void	add_node(t_tokenized_list **head, t_c_char *cmd, t_token token)
{
	t_tokenized_list	*new_node;
	t_tokenized_list	*tmp;

	new_node = malloc(sizeof(t_tokenized_list));
	if (!new_node)
		return ;
	*new_node = (t_tokenized_list){.str = cmd, .token = token, .next = NULL};
	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	lpc_export(new_node, NULL);
}

t_tokenized_list	*lexer(t_c_char **words)
{
	t_tokenized_list	*tokended;
	int					i;

	tokended = NULL;
	i = -1;
	while (words[++i])
	{
		if (words[i][0] == '|' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], PIPE);
		else if (words[i][0] == '<' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], REDIRECT_IN);
		else if (words[i][0] == '>' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], REDIRECT_OUT);
		else if (!ft_strncmp(words[i], ">>", 2) && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], APPEND);
		else if (!ft_strncmp(words[i], "<<", 2) && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], HEREDOC);
		else if (!ft_strncmp(words[i], "||", 2) && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], OR);
		else if (!ft_strncmp(words[i], "&&", 2) && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], AND);
		else
			add_node(&tokended, words[i], WORD);
	}
	return (tokended);
}
