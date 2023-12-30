/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:48 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 18:32:27 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lpc.h"
#include "msh_structs.h"

t_tokenized	*copy_token(t_tokenized obj)
{
	t_tokenized	*ret;

	ret = malloc(sizeof(*ret));
	lpc_export(ret, NULL);
	ret->token = obj.token;
	ret->str = ft_strdup(obj.str);
	lpc_export(ret->str, NULL);
	return (ret);
}

t_list	*extract_cmd_until_pipe(t_tokenized_list **tkn_list)
{
	t_list	*head;

	head = NULL;
	while (*tkn_list && (*tkn_list)->token != PIPE)
	{
		ft_lstadd_back(&head, ft_lstnew(
				copy_token((t_tokenized){
					.token = (*tkn_list)->token,
					.str = (char *)(*tkn_list)->str})));
		*tkn_list = (*tkn_list)->next;
	}
	if (*tkn_list && (*tkn_list)->token == PIPE)
		*tkn_list = (*tkn_list)->next;
	return (head);
}

static void	export_to_lpc(t_list *parsed)
{
	while (parsed)
	{
		lpc_export(parsed, NULL);
		parsed = parsed->next;
	}
}

t_list	*separate_by_pipe(t_tokenized_list *tkn_list)
{
	t_list				*separated_tokens;
	t_tokenized_list	*lst;

	separated_tokens = NULL;
	if (!tkn_list)
		return (NULL);
	lst = tkn_list;
	while (lst)
	{
		ft_lstadd_back(&separated_tokens,
			ft_lstnew(extract_cmd_until_pipe(&lst)));
	}
	ft_lstiter(separated_tokens, (void (*)(void *))export_to_lpc);
	export_to_lpc(separated_tokens);
	return (separated_tokens);
}
