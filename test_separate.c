#include <stdio.h>
#include "libft/libft.h"
#include "msh_structs.h"
#include "parse.h"
#include "typeft.h"

t_list	*separate_by_pipe(t_tokenzied_list **tkn_list);

void	puttoken(void *ptr)
{
	t_tokenized	*tkn;

	tkn = ptr;
	printf("%s\t", ((char *[]){"WORD", "PIPE", "RDR_IN", "RDR_OUT",
			"APPEND", "HEREDOC", "OR", "AND"})[tkn->token]);
	printf(" = %s\n", tkn->str);
}

void	lstfree(void *ptr)
{
	t_list	*lst;

	lst = ((t_list *)ptr)->content;
	ft_lstclear(&lst, free);
}

int	main(int argc, char *argv[])
{
	t_c_char			**wordtab;
	t_tokenzied_list	**tkn_lst;
	t_list				*cmd_lst;
	size_t				size;

	if (argc < 2 || !argv)
		return (-1);
	wordtab = (t_c_char **)ft_str_wordtab(argv[1]);
	tkn_lst = lexer(wordtab, NULL);
	cmd_lst = separate_by_pipe(tkn_lst);
	size = ft_lstsize(cmd_lst);
	while (cmd_lst)
	{
		printf("%lu\n", size - ft_lstsize(cmd_lst));
		ft_lstiter(cmd_lst->content, puttoken);
		cmd_lst = cmd_lst->next;
	}
	ft_lstclear(&cmd_lst, lstfree);
}
