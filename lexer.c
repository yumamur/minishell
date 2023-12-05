#include "parse.h"
#define NULL 0

t_c_char **parse_cmd(t_c_char *cmd, int a, t_parse_arg arg);

void	add_node(t_tokenzied_list **head, t_c_char *cmd, t_token token)
{
	t_tokenzied_list	*tmp;
	t_tokenzied_list	*new_node;
    t_parse_arg	arg;
    
    if (token == 0 && is_seperator(cmd) != 0)
    {
		arg.parsed = (t_c_char **)malloc(sizeof(t_c_char *) * 24);
        arg.parsed = parse_cmd(cmd, 0, arg); // *cmd = "taha|cat>1" -> **seperate = "taha" "|" "cat" ">" "1"
		//print_d(arg.parsed);
        lexer(arg.parsed, head);
		//ft_free_2pt((char **)arg.parsed);
		//print_d(arg.parsed);
		return ;
    }
    new_node = (t_tokenzied_list*)malloc(sizeof(t_tokenzied_list));
	if (!new_node)
        return ;
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

t_tokenzied_list	**lexer(t_c_char **words, t_tokenzied_list **for_tok)
{
	t_tokenzied_list **tokended;
	if (!for_tok)
	{
		tokended = malloc(sizeof(t_tokenzied_list));
		if (!tokended)
			return(0);
		*tokended = NULL;
	}
	else
		tokended = for_tok;
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
