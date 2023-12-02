#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>
#include "typeft.h"
#include "msh_structs.h"
#include "liblpc/lpc.h"

void print_tokenized_list(t_tokenzied_list *head)
{
	while (head != NULL) {
		printf("str: %s, token: %d\n", head->str, head->token);
		head = head->next;
    }
}

void	add_node(t_tokenzied_list **head, t_c_char *cmd, t_token token)
{
	t_tokenzied_list	*tmp;
	t_tokenzied_list	*new_node = (t_tokenzied_list*)malloc(sizeof(t_tokenzied_list));
	if (!new_node)
		printf("memory allocation error");//errorer("bash", "memory allocation error!", stderr(errno), errno);
	new_node->str = cmd;
	new_node->token = token;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_tokenzied_list	**lexer(char **words)
{
	t_tokenzied_list **tokended = malloc(sizeof(t_tokenzied_list));
	if (!tokended)
		return(0);
	*tokended = NULL;
	int	i;

	i = 0;
	while(words[i])
	{
		if (words[i][0] == '|' && ft_strlen(words[i]) == 1)
			add_node(tokended, words[i], PIPE);
		else if (words[i][0] == '<' && ft_strlen(words[i]) == 1)
			add_node(tokended, words[i], REDIRECT_IN);
		else if (words[i][0] == '>' && ft_strlen(words[i]) == 1)
			add_node(tokended, words[i], REDIRECT_OUT);
		else if ((words[i][0] == '>') && words[i][1] == '>' && ft_strlen(words[i]) == 2)
			add_node(tokended, words[i], APPEND);
		else if (words[i][0] == '<' && words[i][1] == '<' && ft_strlen(words[i]) == 2)
			add_node(tokended, words[i], HEREDOC);
		else if (words[i][0] == '|' && words[i][1] == '|' && ft_strlen(words[i]) == 2)
			add_node(tokended, words[i], OR);
		else if (words[i][0] == '&' && words[i][1] == '&' && ft_strlen(words[i]) == 2)
			add_node(tokended, words[i], AND);
		else
			add_node(tokended, words[i], WORD);
		i++;
	}
	return(tokended);
}
