#include "libft/libft.h"
#include "liblpc/typeft.h"
#include "parse.h"
#include "typeft.h"
#include <stdio.h>
#include <stdlib.h>

int	lpc_export(void *addr, ...);
int	lpc_flush(void);

void	free_tokenized_list(t_tokenzied_list *head)
{
	t_tokenzied_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free((char *)tmp->str);
		free(tmp);
	}
}

void	add_node(t_tokenzied_list **head, t_c_char *cmd, t_token token)
{
	t_tokenzied_list	*new_node;

	new_node = malloc(sizeof(t_tokenzied_list));
	if (!new_node)
		return ;
	new_node->str = cmd;
	new_node->token = token;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		t_tokenzied_list	*tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	lpc_export(new_node, free_tokenized_list, NULL);
}

t_tokenzied_list	*lexer(t_c_char **words)
{
	t_tokenzied_list *tokended = NULL;
	int	i;

	i = 0;
	while(words[i])
	{
		if (words[i][0] == '|' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], PIPE);
		else if (words[i][0] == '<' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], REDIRECT_IN);
		else if (words[i][0] == '>' && ft_strlen(words[i]) == 1)
			add_node(&tokended, words[i], REDIRECT_OUT);
		else if ((words[i][0] == '>') && words[i][1] == '>' && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], APPEND);
		else if (words[i][0] == '<' && words[i][1] == '<' && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], HEREDOC);
		else if (words[i][0] == '|' && words[i][1] == '|' && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], OR);
		else if (words[i][0] == '&' && words[i][1] == '&' && ft_strlen(words[i]) == 2)
			add_node(&tokended, words[i], AND);
		else
			add_node(&tokended, words[i], WORD);
		i++;
	}
	lpc_flush();
	return (tokended);
}
